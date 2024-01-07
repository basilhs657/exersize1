
#ifndef PERSON_H
#define PERSON_H



using namespace std;
#include <iostream>
#include <string>


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

        static int person_counter;//keeping track of object Persons created
    public:
        Person(string first_name , string last_name , int age  , string doc_number , string email);

        Person();

        void Person_counter();

        void SetAge(int age);

        void SetName(string first_name);

        void SetSecondName(string last_name);

        void SetDoc_Num(string doc_number);

        virtual void SetEmail(string email)const = 0;

        friend ostream & operator<<(ostream& par  ,const Person& pr);

        friend istream & operator>>(istream& ins , Person& det);

        string GetFirstName();

        string GetLastName();

        int getAge();

        string GetDocNumber();

        string GetEmail();

        ~Person();
};

#endif // PERSON_H