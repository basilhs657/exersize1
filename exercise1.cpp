#include <iostream>
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
	
    /* data */
public:
    Person(long int x , string first_name , string last_name ,  string taftotita):AM(x),name(first_name),second_name(last_name) , AN(taftotita){}; //initializer list
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
	long int GetAM(){return AM;};
	string GetFirstName(){return name;};
	string GetLastName(){return second_name;};
	string GetAN(){return AN;};
    ~Person();
};



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

}
