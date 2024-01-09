
#include "course.h"

Course:: Course(string subject_name , bool mandatory , int ECTS , Semester* semester): subject_name(subject_name) , mandatory(mandatory) , ECTS(ECTS) , semester(semester){}; 
void Course::SetSubjectName(string subject_name ){subject_name = subject_name;};
void Course::SetMandatory(string if_needed){
    if(if_needed=="yes") mandatory=true;
    else mandatory=false;
}
void Course::display(){
    cout<< subject_name << endl << "Mandatory: " << (mandatory ? "YES" : "NO") << endl << "number of ECTS: " << ECTS << endl << "number of semester: ";
    semester->display();  
}
void Course::changeSemester(Semester* new_semester){
    cout << "the semester of this lesson has been changed from " << endl;
    semester->display();
    semester = new_semester;
    cout << "to: " << endl;
    semester->display();
    
}
void Course::SetECTS(int ECTS ){ECTS=ECTS;};
Course::~Course(){};