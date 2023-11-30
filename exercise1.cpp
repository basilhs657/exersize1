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
	// long int AM; //ΑΡΙΘΜΟΣ ΜΗΤΡΟΟ
	int age; // age of person
	string doc_number; //arithmos astinomikhs taftotitas
	string email; // email

	static int person_counter;;//keeping track of object Persons created

public:
    Person(string first_name , string last_name , int age  , string doc_number , string email):first_name(first_name),last_name(last_name), age(age) , doc_number(doc_number) , email(email){
	//cout << "Person has been constructed" << endl;
		person_counter++;
	}; //initializer list
	Person(){}; //the constructor in to use the istream and ostream function 

	void Person_counter(){
        cout << "The number of people created is: " << person_counter << endl; //PRINTING THE AMOUNT OF PERSONS CREATED
    }

	//SETTERS
	// void SetAM(long int arithmos){ //imutators
	// 	AM=arithmos;					
	// } 			
	void SetAge(int age){
		age = age;
	}
	void SetName(string first_name){	
		first_name=first_name;			
	}					
	void SetSecondName(string last_name){
		last_name=last_name;
	}
	void SetDoc_Num(string doc_number){
		doc_number=doc_number;
	}
	void SetEmail(string email){
		email = email;
	}
	friend ostream & operator<<(ostream& par  ,const Person& pr) {
		par << "First Name: " << pr.first_name << endl << "Last Name: "<< pr.last_name << endl << "Age: " <<  pr.age << endl << "email: " << pr.email << endl << "Arithmo tautothtas: " << pr.doc_number << endl; 
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
		cout << "email: ";
		ins >> det.email;
		cout << "Document number: ";
		ins >> det.doc_number;
		cout << endl;
		return ins;
	}

	//MUTATORS
	// long int GetAM(){return AM;};
	string GetFirstName(){return first_name;};
	string GetLastName(){return last_name;};
	int getAge(){return age;};
	string GetDocNumber(){return doc_number;};
	string GetEmail(){return email;};

	~Person(){
		// cout << "Person has been destructed" << endl;
	}
};



class Secretary
{
private:
	map<string, Person *> person_map ; // we gonna use map key:document Number value:person object
	map<string , Person *> extended_identificator; // finding a person with his first name and last name 

public:
	Secretary(){}; //empty constructor
	Secretary& operator+(Person& person){
			Person* pr = new Person(person); 
			person_map[pr->GetDocNumber()] = pr;
			string first_last_name_email  = pr->GetFirstName() + pr->GetLastName() + pr->GetEmail();  
			extended_identificator[first_last_name_email] = pr;
			return *this;
	}
	friend istream & operator>>(istream & input ,Secretary& sec){
		Person person; 
		input >> person;
		auto per = sec.person_map.find(person.GetDocNumber());
		if(per == sec.person_map.end()){
		  	sec=sec+person; //using the + operatot with the function above
		}
	 	else{
		  	cout << "Person already exists!" << endl;
		}
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
			for(auto mp = person_map.begin(); mp != person_map.end(); mp++){
				delete mp->second;
			}			
			for(auto mp = sec.person_map.begin(); mp != sec.person_map.end(); mp++){
				Person* cloned = new Person(*(mp->second)); 
				person_map[mp->first] = cloned;
				string data = cloned->GetFirstName() + cloned->GetLastName() + cloned->GetEmail();
				extended_identificator[data] = cloned;
			}			
		}
		return *this;
	}

	Secretary(const Secretary& other):person_map(other.person_map){
	 	for (auto person = other.person_map.begin(); person != other.person_map.end(); person++){
    		Person* clone = new Person(*(person->second));
        	person_map[person->first] = clone;
     	}
	}; // copy constructor 

	void NumberOfPersons(const Secretary& other){
		other.person_map.begin()->second->Person_counter();
	}

	void ExistingAM(Person * person){
		if(person_map[person->GetDocNumber()]==NULL){ //the value of the map is a pointer 
			cout<<" PERSON DOES NOT EXIST"<< endl;
		}
		else
		{
			cout << "PERSON EXISTS" << endl;
			cout << *person <<endl << endl; 
		}		
	}
	void findUsingData(){
		string name , last_name , email; 
		cout << "name of the person you are searcing: " << endl;
		cin >> name; 
		cout << "last name of the person you are seaching: " << endl;
		cin >> last_name; 
		cout <<"email of the person you are seacring: "<< endl;
		cin >> email;
		string data = name + last_name + email;
		if(extended_identificator[data] == NULL){
			cout << "Person does not exist!" << endl;
		}
		else{
			cout << "PERSON EXISTS : ";
			cout << *extended_identificator[data] << endl;  
		}
	}
	~Secretary(){
		for(auto mp = person_map.begin(); mp != person_map.end(); mp++){
			delete mp->second;
		}			
    	person_map.clear();
		extended_identificator.clear();
		cout << "Secretary has been destructed" << endl << endl;
	}


};

int Person::person_counter = 0;


int main(){
	//initializing a person 
	Person p;
	cin >> p;
	//printing the number of persons created 
	p.Person_counter();
	Secretary secretary;
	cin >> secretary;
	cin >> secretary;
	secretary.findUsingData();
	Person find;
 	cin >> find;
 	Secretary replace;
 	replace = secretary;
	replace.findUsingData();
 	secretary.ExistingAM(&find);
 	p.Person_counter();
	replace.NumberOfPersons(replace);
}
