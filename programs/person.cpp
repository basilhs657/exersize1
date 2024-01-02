#include "person.h"

	int Person::person_counter = 0;
    Person::Person(string first_name , string last_name , int age  , string doc_number , string email):first_name(first_name),last_name(last_name), age(age) , doc_number(doc_number) , email(email){
		person_counter++;
	}; //initializer list

	Person::Person(){}; //the constructor in to use the istream and ostream function 

	void Person::Person_counter(){
        cout << "The number of people created is: " << person_counter << endl; //PRINTING THE AMOUNT OF PERSONS CREATED
    }

	//SETTERS
	void Person::SetAge(int age){
		age = age; //setting the age
	}
	void Person::SetName(string first_name){	
		first_name=first_name;	//setting the first Name
	}					
	void Person::SetSecondName(string last_name){
		last_name=last_name;  //setting the last name
	}
	virtual void Person::SetDoc_Num(string doc_number){
		doc_number=doc_number;  //setting the document number
	}
	void Person::SetEmail(string email){
		email = email;	//setting the email
	}
	//creating the << operator overload that will return the person data as an ostream 
	ostream & operator<<(ostream& par  ,const Person& pr) {
		par << "First Name: " << pr.first_name << endl << "Last Name: "<< pr.last_name << endl << "Age: " <<  pr.age << endl << "email: " << pr.email << endl << "Arithmo tautothtas: " << pr.doc_number << endl; 
		return par;
	}
	//creating the >> operator overload that will wait as input from the user and will set the data given the input the user gives 
	istream & operator>>(istream& ins , Person& det){
		Person::person_counter++; //because we create a new person without the constructor this means we should update the person counter
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

	//GETTERS
	string Person::GetFirstName(){return first_name;};
	string Person::GetLastName(){return last_name;};
	int Person::getAge(){return age;};
	string Person::GetDocNumber(){return doc_number;};
	string Person::GetEmail(){return email;};
	// DESTRUCTOR
	Person::~Person(){
		//we reduce the number of person that exist 
		person_counter--;
	}
