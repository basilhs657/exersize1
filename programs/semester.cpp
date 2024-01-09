#include "semester.h"

Semester::Semester(int number_of_semester , string start_of_semestet , string end_of_semester): number_of_semester(number_of_semester) , start_of_semester(start_of_semestet) , end_of_semester(end_of_semester){};

void Semester::display(){
    cout<< "Number of semester: " << number_of_semester<< endl << "start of the semester: "<< start_of_semester << endl << "end of semester: " << end_of_semester << endl;

}


Semester::~Semester(){};