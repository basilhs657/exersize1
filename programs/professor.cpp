#include "professor.h"

professor::professor(string firstname , string lastname , int age  , string doc_number ,string email , int office_number , int years_of_woking , string lesson ):Person(firstname,lastname,age,doc_number,email),office_number(office_number),years_of_woking(years_of_woking),lesson(lesson){};
professor::professor(){};
void professor::SetYearsOfWorking(int years_of_woking){ years_of_woking=years_of_woking;};
void professor::SetLesson(string lesson ){lesson=lesson ; }; 
void professor::SetOfficeNumber(int office_number){office_number=office_number;};
void professor::SetEmail(){
    string ans , my_email ; 
    cout << "Do you want an academic or your personal email ;" << endl ; 
    cin >> ans ;  
    cout << "Write your email"  << endl ;
    cin >> my_email;
    email=my_email; 
}
professor::~professor(){};
 