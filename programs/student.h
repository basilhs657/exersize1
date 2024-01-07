#include "person.h"
#include <map>


class Student: public Person
{
private:
    string AM;   // Αριθμος μιτροω 
    int num_Of_subjects; //αριθμος μαθηματων 
    int MO;  //Μεσος ορος  του μαθητη 

public:
    Student(string firstName , string lastName , int age , string doc_number ,string email , string AM , int num_Of_subjects , int MO);

    void SetEmail(string doc_num) const;

    void setAM(string AM);

    void setNumOfSubjects(int num_Of_subjects);

    void SetMO(int MO);

    string GiveAM();
    
    int GiveNum_Of_subjects();

    int GiveMO();

    virtual ~Student();

};
