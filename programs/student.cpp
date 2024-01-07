#include "student.h" 

//ο constructor του student 
Student::Student(string firstName , string lastName , int age , string doc_number ,string email , string AM , int num_Of_subjects , int MO):Person(firstName , lastName , age , doc_number , email) , AM(AM), num_Of_subjects(num_Of_subjects) , MO(MO){};

void setAM(int AM){
    cout<<"Give the AM: " << endl;
    AM = AM;

}

void setNumOfSubjects(int num_Of_subjects){
    cout << "Give number of Subjects: " << endl;

}

void SetMO(int MO){
    cout << "Give the MO: "<<endl;
    MO = MO;
}
//giving the student email
void Student::SetEmail(string email)const{
    cout << "Give student email: " << endl;
    email = email;
}

string Student::GiveAM(){
    return Student::AM;
}

int Student::GiveNum_Of_subjects(){
    return Student::num_Of_subjects;
}

int Student::GiveMO(){
    return Student::MO;
}


Student::~Student(){};