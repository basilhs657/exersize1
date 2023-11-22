#include <iostream>
#include<ostream>
#include<istream>
#include <string>
// athliopt mono
using namespace std;
//class Student{
//	long int Am; //arithmos mitrwou
//	string email;
//	string An ; // arithmos astinomikhw taftothtas 
//	string name ; 
//	string second_name ; 
//	public:
//		Student(long int arithmos_mitrow , string mail , string taftotita )Am(arithmos_mitrow),{}
//};
//this
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
		person_counter++;
	}; //initializer list
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
	friend ostream& operator<<(ostream& par  ,const Person& pr) {
		par << "Name: " << pr.name << endl << "Last Name: "<< pr.second_name << endl << "Arithmo mitro: " << pr.AM << endl << "Arithmo tautothtas: " << pr.AN << endl; 
		return par;
	}
	friend istream& operator>>(istream& ins , const Person det){
		//
	}


	long int GetAM(){return AM;};
	string GetFirstName(){return name;};
	string GetLastName(){return second_name;};
	string GetAN(){return AN;};
    // ~Person(); destructor
};

int Person::person_counter = 0;

class Secretary
{
private:
    /* data */
public:
    Secretary(/* args */);
    ~Secretary();
};

Secretary::Secretary(/* args */)
{
}

Secretary::~Secretary()
{
}


int main(){
	Person p(11112233 , "bill" , "sikakis" , "albanian");
	//test
	cout << "name is: " << p.GetFirstName() << endl << "surname: " << p.GetLastName() << endl << "AM: " << p.GetAM() << endl;
    p.Person_counter();
    return 0;
}
