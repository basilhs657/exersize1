#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"


class professor:public Person
{ 
private:
    string lesson ; 
    int office_number  ;
    int years_of_woking ;
    string email;

public:
    professor(string firstname , string lastname , int age  , string doc_number , string y , int office_number , int years_of_woking , string lesson );
    professor();
    void SetYearsOfWorking(int years_of_woking);
    void SetLesson(string lesson );
    void SetOfficeNumber(int office_number) ; 
    void SetEmail();
    ~professor();
};

#endif


