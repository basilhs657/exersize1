#include "person.h"


class Student: public Person
{
private:
    string dateOfSighning;
    string AM;
    string course;
public:
    Student(string dateOfSighninh , string AM , string course): dateOfSighning(dateOfSighning) , AM(AM) , course(course) {};
    ~Student();
};
