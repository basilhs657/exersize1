#include "professor.h"

Professor::Professor(string firstname , string lastname , int age  , string doc_number ,string email , int office_number , int years_of_woking , string lesson ):Person(firstname,lastname,age,doc_number,email),office_number(office_number),years_of_woking(years_of_woking),lesson(lesson){};
Professor::Professor(){};
void Professor::SetYearsOfWorking(int years_of_woking){ years_of_woking=years_of_woking;};
void Professor::SetLesson(string lesson ){lesson=lesson ; }; 
void Professor::SetOfficeNumber(int office_number){office_number=office_number;};
void Professor::SetEmail(string email)const {
    string ans , my_email ; 
    cout << "Do you want an academic or your personal email ;" << endl ; 
    cin >> ans ;  
    cout << "Write your email"  << endl ;
    cin >> my_email;
    email=my_email; 
}
Professor::~Professor(){};
