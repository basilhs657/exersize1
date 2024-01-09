#ifndef COURSE_H
#define COURSE_H
using namespace std;
#include "semester.h"
#include <string>
#include <iostream>


class Course
{
    string subject_name; 
    bool mandatory; //einai ypoxreotiko 
    int ECTS;
    Semester* semester;

public:
    Course(string subject_name , bool mandatory , int ECTS , Semester* semester); 
    void display();
    void SetSubjectName(string subject_name);
    void SetECTS(int ECTS);
    void SetMandatory(string if_needed);
    void changeSemester(Semester* semester);
    ~Course();
};
#endif 

