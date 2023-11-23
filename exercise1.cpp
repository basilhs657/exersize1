#include <iostream>
#include<ostream>
#include<istream>
#include <string>
// athliopt mono
using namespace std;
class Person
{
private:
	long int AM; //arithmos mitrwoy
	string second_name;//
	string name	;//o
	string AN; //arithmos astinomikhs taftot

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
		cout << "give Name" << endl;
		ins  >> det.name;
		cout << "give last Name:" << endl;
		ins  >>  det.second_name; 
		cout << "give Am" << endl;
		ins >> det.AM;
		cout << "give AN" << endl;
		ins >> det.AN;
		return ins;
		//
	}

	long int GetAM(){return AM;};
	string GetFirstName(){return name;};
	string GetLastName(){return second_name;};
	string GetAN(){return AN;};
	~Person(){
		cout << "Person has been destructed" << endl;
	}
};

int Person::person_counter = 0;

// class Secretary
// {
// private:
//     /* data */
// public:
//     Secretary(/* args */);
//     ~Secretary();
// };

// Secretary::Secretary(/* args */)
// {
// }

// Secretary::~Secretary()
// {
// }

int main(){
	Person p(11112233 , "bill" , "sikakis" , "albanian");
	//test
	cout << "name is: " << p.GetFirstName() << endl << "surname: " << p.GetLastName() << endl << "AM: " << p.GetAM() << endl;
    p.Person_counter();
	
//use of operation overload functions  (istream and ostream)
	Person p1 ;
	
	cin >> p1; 
	cout << p1;
    return 0;
}
