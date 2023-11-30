#include <iostream>
#include<ostream>
#include<istream>
#include<map>
#include <string>

using namespace std;


class Person
{
private:
	long int AM; //arithmos mitrwoy
	string second_name;//
	string name	; // onoma
	string AN; //arithmos astinomikhs taftotitas

	static int person_counter;;//keeping track of object Persons created
    /* data */

public:
    Person(long int x , string first_name , string last_name ,  string taftotita):AM(x),name(first_name),second_name(last_name) , AN(taftotita){
		cout << "Person has been constructed" << endl;
		person_counter++;
	}; //initializer list
	
	Person(){}; //the constructor in to use the istream and ostream function 
	void Person_counter(){
        cout << "The number of people created is: " << person_counter << endl;
    }
	void SetAM(long int arithmos){ //imutators
		AM=arithmos;					
	} 			
	void SetName(string first_name){	
		name=first_name;			
	}					
	void SetSecondName(string last_name){
		second_name=last_name;
	}
	void SetAN(string taftotita){
		AN=taftotita;
	}
	friend ostream & operator<<(ostream& par  ,const Person& pr) {
		par << "Name: " << pr.name << endl << "Last Name: "<< pr.second_name << endl << "Arithmo mitro: " << pr.AM << endl << "Arithmo tautothtas: " << pr.AN << endl; 
		return par;
	}
	friend istream & operator>>(istream& ins ,/*const not needed i think cause we change value of the pobject */ Person& det){
		person_counter++; //because we create a new person without the constructor this means we should update the person counter
		cout << "give Name" << endl;
		ins  >> det.name;
		cout << "give last Name:" << endl;
		ins  >>  det.second_name; 
		cout << "give AM :" << endl;
		ins >> det.AM;
		cout << "give AN :" << endl;
		ins >> det.AN;
		return ins;
	}

	long int GetAM(){return AM;};
	string GetFirstName(){return name;};
	string GetLastName(){return second_name;};
	string GetAN(){return AN;};
	~Person(){
		cout << "Person has been destructed" << endl;
	}
};


class Secretary
{
private:
	map<long int, Person *> person_map ; // we gonna use map key:AM(aritmos mitrwou) value:person object
	map<string , Person *> last_name_map;

public:
	Secretary(){}; //empty constructor
	Secretary& operator+( Person& person){
		Person * pr = new Person(person);  // dynamic allocation 
		person_map[pr->GetAM()]=  pr; //add the person to the map	
		return *this ;//return the objects pointer
	}
	friend istream & operator>>(istream & input ,Secretary& sec){
		Person person ; 
		input >> person ;
		sec=sec+person; //using the + operatot with the function above 
		return input;
	}
	friend ostream& operator<<(ostream& output,const Secretary& sec){
		cout << endl;
		for(auto itr =sec.person_map.begin() ; itr != sec.person_map.end() ; itr++){
			output << *itr->second;	 //using the Persons class << operartor
			output << endl;
		}
		return output;
	}

	Secretary& operator=(const Secretary& sec){
		if(this != &sec){
				for(auto mp = person_map.begin(); mp != person_map.end(); mp++){

				delete mp->second;
			}
			person_map.clear();

			for(auto mp = sec.person_map.begin(); mp != sec.person_map.end(); mp++){
				Person* cloned = new Person(*(mp->second)); 

				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!person map: " << cloned->GetAM();
				person_map[mp->first] = cloned;

			}			
					}	
		return *this;
	}

	Secretary(const Secretary& other):person_map(other.person_map){
		for(auto mp = other.person_map.begin(); mp != other.person_map.end(); mp++){
			Person* cloned = new Person(*(mp->second)); 
			person_map[mp->first] = cloned;
		}
	}; // copy constructor 

	void ExistingAM(Person * person ){
		if(person_map[person->GetAM()]==NULL){ //the value of the map is a pointer 
			cout << person->GetAM() << endl;
			cout << person_map[person->GetAM()] << endl;
			cout<<" PERSON DOES NOT EXIST"<< endl;
		}
		else
		{
			cout << "PERSON EXISTS" << endl;
			cout << *person; 
		}		
	}
	~Secretary(){
		for(auto pr = person_map.begin(); pr != person_map.end(); pr++){
		  	delete pr->second;
		}
		auto pr =person_map.end();
		delete pr->second;
	
	person_map.clear();
		cout << "secretary has been destructed" << endl;
	}
};

int Person::person_counter = 0;


int main(){
	
	Person p;
	cin >> p;
	p.Person_counter();
	Secretary secretary;
	cin >> secretary;
	cin >> secretary;
	cin >> secretary;
	Person find;
 	cin >> find;
 	Secretary replace;
 	replace = secretary;
 	secretary.ExistingAM(&find);
 	p.Person_counter();
}
