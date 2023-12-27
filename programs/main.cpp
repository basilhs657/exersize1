#include "person.h"
#include "secretary.h"

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
	//checking if the person exists
	secretary.Find_with_doc_number();
	//initializing a second secretary
 	Secretary replace;
	//inserting the previus secretary to replace to check the = operator overload and the copy constructor s
 	replace = secretary;
	//we add a new person to replace
	cin >> replace;
	//we try to find if a person exists in replace
	replace.findUsingData();
	//we print all the persons of secretary 
	cout << secretary;
	//we print all the person of replace
	
	cout << replace;

	//creating a new person and checking if the person can be added to the secretery 
	Person p("bill" , "t" , 12 , "123" , "213");
	replace = replace + p;
	return 0;
}
