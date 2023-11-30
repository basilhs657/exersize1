#include <iostream>
#include<ostream>
#include<istream>
#include<map>
#include <string>

using namespace std;


class Person
{
private:
	//PERSON Data
	string first_name; // first_name
	string last_name;//last name
	long int AM; //ΑΡΙΘΜΟΣ ΜΗΤΡΟΟ
	int age; // age of person
	string doc_number; //arithmos astinomikhs taftotitas

	static int person_counter;;//keeping track of object Persons created

public:
    Person(string first_name , string last_name , int age , string AN , string doc_number):first_name(first_name),last_name(last_name), age(age) , AM(AM), doc_number(doc_number){
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
	void SetAge(int age){
		age = age;
	}
	void SetName(string first_name){	
		first_name=first_name;			
	}					
	void SetSecondName(string last_name){
		last_name=last_name;
	}
	void SetAN(string doc_number){
		doc_number=doc_number;
	}
	friend ostream & operator<<(ostream& par  ,const Person& pr) {
		par << "First Name: " << pr.first_name << endl << "Last Name: "<< pr.last_name << endl << "Age: " <<  pr.age << endl << "Arithmo mitro: " << pr.AM << endl << "Arithmo tautothtas: " << pr.doc_number << endl; 
		return par;
	}
	friend istream & operator>>(istream& ins , Person& det){
		person_counter++; //because we create a new person without the constructor this means we should update the person counter
		cout << "Please provide the following information about the person: " << endl;
		cout << "First name: ";
		ins  >> det.first_name;
		cout << "Last Name: ";
		ins  >>  det.last_name; 
		cout << "Age: ";
		ins >> det.age;
		cout << "University identification number (should contain an 11 digit number):";
		ins >> det.AM;
		cout << "Document number: ";
		ins >> det.doc_number;
		return ins;
	}

	long int GetAM(){return AM;};
	string GetFirstName(){return first_name;};
	string GetLastName(){return last_name;};
	int getAge(){return age;};
	string GetAN(){return doc_number;};

	~Person(){
		cout << "Person has been destructed" << endl;
	}
};



class Secretary
{
private:
	map<long int, Person *> person_map ; // we gonna use map key:AM(aritmos mitrwou) value:person object
	// map<string , Person *> last_name_map;

public:
	Secretary(){}; //empty constructor
	Secretary& operator+(Person& person){
			auto it = person_map.find(person.GetAM());
			if (it == person_map.end()) {
			Person* pr = new Person(person); // Dynamic allocation for new Person object
			person_map[pr->GetAM()] = pr;   // Add the person to the map
			} else {
			// Person already exists, update its information
			*(it->second) = person;
    		}
			return *this;
	}
	friend istream & operator>>(istream & input ,Secretary& sec){
		Person person; 
		input >> person;
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
		if (this != &sec){
			for (const auto& person : person_map) {
				delete person.second;
    		}
			for(auto mp = sec.person_map.begin(); mp != sec.person_map.end(); mp++){
			Person* cloned = new Person(*(mp->second)); 
			person_map[mp->first] = cloned;
			}			
		}
		return *this;
	}

	Secretary(const Secretary& other):person_map(other.person_map){
	 	for (const auto& person : other.person_map) {
         Person* cloned = new Person(*(person.second));
         person_map[person.first] = cloned;
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
		for (auto& person : person_map) {
        	delete person.second;
    	}
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
