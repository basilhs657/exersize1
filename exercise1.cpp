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
	string doc_number; //arithmos astinomikhs taftotitas h diavatiriou
	string email; // email

	static int person_counter;;//keeping track of object Persons created

public:
    Person(string first_name , string last_name , int age  , string doc_number , string email):first_name(first_name),last_name(last_name), age(age) , doc_number(doc_number) , email(email){
		person_counter++;
	}; //initializer list

	Person(){}; //the constructor in to use the istream and ostream function 

	void Person_counter(){
        cout << "The number of people created is: " << person_counter << endl; //PRINTING THE AMOUNT OF PERSONS CREATED
    }

	//SETTERS
	void SetAge(int age){
		age = age; //setting the age
	}
	void SetName(string first_name){	
		first_name=first_name;	//setting the first Name
	}					
	void SetSecondName(string last_name){
		last_name=last_name;  //setting the last name
	}
	void SetDoc_Num(string doc_number){
		doc_number=doc_number;  //setting the document number
	}
	void SetEmail(string email){
		email = email;	//setting the email
	}
	//creating the << operator overload that will return the person data as an ostream 
	friend ostream & operator<<(ostream& par  ,const Person& pr) {
		par << "First Name: " << pr.first_name << endl << "Last Name: "<< pr.last_name << endl << "Age: " <<  pr.age << endl << "email: " << pr.email << endl << "Arithmo tautothtas: " << pr.doc_number << endl; 
		return par;
	}
	//creating the >> operator overload that will wait as input from the user and will set the data given the input the user gives 
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

	//GETTERS
	string GetFirstName(){return first_name;};
	string GetLastName(){return last_name;};
	int getAge(){return age;};
	string GetDocNumber(){return doc_number;};
	string GetEmail(){return email;};
	// DESTRUCTOR
	~Person(){
		//we reduce the number of person that exist 
		person_counter--;
	}
};



class Secretary
{
private:
	map<string, Person *> person_map ; //USING A MAP TO ASSIGHN A KEY (DOCUMENT VALUE) TO FIND A PERSON OBJECT
	map<string , Person *> extended_identificator; // USING A MAP TO ASSIGHN A KEY(FIRST NAME , LAST NAME , EMAIL) TO FIND A PERSON OBJECT

public:
	Secretary(){}; //empty constructor
	//creating the + operator overload
	Secretary& operator+(Person& person){
		//allocating memory to store a person in our two maps
		Person* pr = new Person(person); 
		//inserting a new pair with the key document number and  it's pair the pr (person object)
		person_map[pr->GetDocNumber()] = pr;
		//creating the string that will represent the key for our other map to find the person 
		string first_last_name_email  = pr->GetFirstName() + pr->GetLastName() + pr->GetEmail();
		//we use the same person that we allocatd memory before   
		extended_identificator[first_last_name_email] = pr;
		return *this;
	}
	//creating the >> operator overload
	friend istream & operator>>(istream & input ,Secretary& sec){
		//creating a new object
		Person person; 
		//using the >> overload function that we have created in the person object that will create and assighn values to a new person 
		input >> person;
		//trying to find if the data that was given as input corresponds to another person that already exists
		auto per = sec.person_map.find(person.GetDocNumber());
		//if the person does not exist which means the find dunction returned the map.end()
		if(per == sec.person_map.end()){
		  	sec=sec+person; //we will add the person to our secretary using the + fucntion above
		}
	 	else{
			//if it already exists we print the following message
		  	cout << "Person already exists!" << endl;
		}
		//we return the input
		return input;
	}
	// creatin the << operator overload function
	friend ostream& operator<<(ostream& output,const Secretary& sec){
		cout << endl;
		//we traverse the whole person_map to print all the person in our secretry class
		for(auto itr =sec.person_map.begin() ; itr != sec.person_map.end() ; itr++){
			output << *itr->second;	 //using the Persons class << operartor overload function
			output << endl;
		}
		//we return the output
		return output;
	}
	//creating the = operator overload function 
	Secretary& operator=(const Secretary& sec){
		//we check if ..
		if (this != &sec){
			for(auto mp = person_map.begin(); mp != person_map.end(); mp++){
				//we delete the previus data
				delete mp->second;
			}			
			for(auto mp = sec.person_map.begin(); mp != sec.person_map.end(); mp++){
				//and we do a deep scan of the current data that we will clone to our assighned secretary 
				Person* cloned = new Person(*(mp->second)); 
				person_map[mp->first] = cloned;
				string data = cloned->GetFirstName() + cloned->GetLastName() + cloned->GetEmail();
				extended_identificator[data] = cloned;
			}			
		}
		return *this;
	}

	Secretary(const Secretary& other):person_map(other.person_map){
		//doing a deep scan since our secretary function works with dynamin memory allocation 
	 	for (auto person = other.person_map.begin(); person != other.person_map.end(); person++){
    		Person* clone = new Person(*(person->second));
        	person_map[person->first] = clone;
     	}
	}; // copy constructor 

	//having access to all the different persons created 
	void NumberOfPersons(const Secretary& other){
		other.person_map.begin()->second->Person_counter();
	}
	//creatin a function that will get as input another person and using it's document number it will find if the person exists in the document class
	void ExistingAM(){
		string document;
		cout << "Give the number of the document of the person you are trying to find: ";
		cin >> document;
		
		if(person_map.find(document) == person_map.end()){ //if the find fucntion returned map.end then we didnt find the person  
			cout<<" PERSON DOES NOT EXIST"<< endl;
		}
		else
		{
			
			cout << "PERSON EXISTS" << endl;
			cout << "The data of the person you are looking for: " << endl;
			cout <<*person_map[document] <<endl << endl; 
		}		
	}
	//creating a function that will ask the user for the first and last name and email to find if the prson exists in our secretary class
	void findUsingData(){
		string name , last_name , email; 
		cout << "Please pprovide the following information about the person you are searching: " << endl;
		cout << "name of the person you are searcing: " << endl;
		cin >> name; 
		cout << "last name of the person you are seaching: " << endl;
		cin >> last_name; 
		cout <<"email of the person you are seacring: "<< endl;
		cin >> email;
		//we add the data to create an accurate key 
		string data = name + last_name + email;
		//we check if the person exists
		if(extended_identificator.find(data) == extended_identificator.end()){ 
			cout << "Person does not exist!" << endl;
		}
		else{
			cout << "PERSON EXISTS : " << endl;
			cout << "The data of the person you are looking for: " << endl;
			cout << *extended_identificator[data] << endl;  
		}
	}
	//DESTRUCTORS 
	~Secretary(){
		//we delete all the dynamically allocated memory for the person objets we have created
		for(auto mp = person_map.begin(); mp != person_map.end(); mp++){
			delete mp->second;
		}			
		//since we used the same address for the object person in our person_map and extended_identificator map we don't have to delete the memory 
		//for our extended_identificator map
		//we delete the keys
    	person_map.clear();
		extended_identificator.clear();
		cout << "Secretary has been destructed" << endl << endl;
	}


};

int Person::person_counter = 0;


int main(){
	//Checking the functionallity of secretary
	//initializing an object of class secretary
	Secretary secretary;
	//inserting a new person to our secretary finction 
	cin >> secretary;
	//inserting another person to our secretary function 
	cin >> secretary;
	//finfing a person using his fisrt name , last name and email
	secretary.findUsingData();
	//initializing a new person 
	Person find;
 	cin >> find;
	//checking if the person exists
	secretary.ExistingAM();
	//initializing a second secretary
 	Secretary replace;
	//inserting the previus secretary to replace to check the = operator overload and the copy constructor s
 	replace = secretary;
	//we add a new person to replace
	cin >> replace;
	//we try to find if a person exists in replace
	replace.findUsingData();
	//we output the number of persons created
	replace.NumberOfPersons(replace);
	//we print all the persons of secretary 
	cout << secretary;
	//we print all the person of replace
	cout << replace;

	return 0;
}
