#include "secretary.h"


	Secretary::Secretary(){}; //empty constructor
	//creating the >> operator overload
	
	// creatin the << operator overload function
	ostream& operator<<(ostream& output,const Secretary& sec){
		cout << endl;
		//we traverse the whole person_map to print all the person in our secretry class
		for(auto person_traverse =sec.person_map.begin() ; person_traverse != sec.person_map.end() ; person_traverse++){
			output << *person_traverse->second;	 //using the Persons class << operartor overload function
			output << endl;
		}
		//we return the output
		return output;
	}
	//creating the = operator overload function 
	// Secretary& Secretary::operator=(const Secretary& sec){
	// 	//we check if ..
	// 	if (this != &sec){
	// 		for(auto person_traverse = person_map.begin(); person_traverse != person_map.end(); person_traverse++){
	// 			//we delete the previus data
	// 			delete person_traverse->second;
	// 		}			
	// 		for(auto person_traverse = sec.person_map.begin(); person_traverse != sec.person_map.end(); person_traverse++){
	// 			//and we do a deep scan of the current data that we will clone to our assighned secretary 
	// 			Person* cloned = new Person(*(person_traverse->second)); 
	// 			person_map[person_traverse->first] = cloned;
	// 			string data = cloned->GetFirstName() + cloned->GetLastName() + cloned->GetEmail();
	// 			extended_identificator[data] = cloned;
	// 		}			
	// 	}
	// 	return *this;
	// }

	// Secretary::Secretary(const Secretary& other):person_map(other.person_map){
	// 	//doing a deep scan since our secretary function works with dynamin memory allocation 
	//  	for (auto person = other.person_map.begin(); person != other.person_map.end(); person++){
    // 		Person* clone = new Person(*(person->second));
    //     	person_map[person->first] = clone;
    //  	}
	// }; // copy constructor 

	// //creatin a function that will get as input another person and using it's document number it will find if the person exists in the document class
	// void Secretary::Find_with_doc_number(){
	// 	string document;
	// 	cout << "Give the number of the document of the person you are trying to find: ";
	// 	cin >> document;
		
	// 	if(person_map.find(document) == person_map.end()){ //if the find fucntion returned map.end then we didnt find the person  
	// 		cout<<" PERSON DOES NOT EXIST"<< endl;
	// 	}
	// 	else
	// 	{
	// 		cout << "PERSON EXISTS" << endl;
	// 		cout << "The data of the person you are looking for: " << endl;
	// 		cout <<*person_map[document] <<endl << endl; 
	// 	}		
	// }   
	// //creating a function that will ask the user for the first and last name and email to find if the prson exists in our secretary class
	// void Secretary::findUsingData(){
	// 	string name , last_name , email; 
	// 	cout << "Please provide the following information about the person you are searching: " << endl;
	// 	cout << "name of the person you are searcing: " << endl;
	// 	cin >> name; 
	// 	cout << "last name of the person you are seaching: " << endl;
	// 	cin >> last_name; 
	// 	cout <<"email of the person you are seacring: "<< endl;
	// 	cin >> email;
	// 	//we add the data to create an accurate key 
	// 	string data = name + last_name + email;
	// 	//we check if the person exists
	// 	if(extended_identificator.find(data) == extended_identificator.end()){ 
	// 		cout << "Person does not exist!" << endl;
	// 	}
	// 	else{
	// 		cout << "PERSON EXISTS : " << endl;
	// 		cout << "The data of the person you are looking for: " << endl;
	// 		cout << *extended_identificator[data] << endl;  
	// 	}
	// }
	//DESTRUCTORS 
	Secretary::~Secretary(){
		//we delete all the dynamically allocated memory for the person objets we have created
		for(auto person_traverse = person_map.begin(); person_traverse != person_map.end(); person_traverse++){
			delete person_traverse->second;
		}			
		//since we used the same address for the object person in our person_map and extended_identificator map we don't have to delete the memory 
		//for our extended_identificator map
		//we delete the keys
    	person_map.clear();
		extended_identificator.clear();
		cout << "Secretary has been destructed" << endl << endl;
	}
