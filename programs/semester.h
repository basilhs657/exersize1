#define SEMESTER_H
#ifdef SEMESTER_H
using namespace std;
#include <iostream>
#include <string>

class Semester
{
private:
    int number_of_semester; // ο αριθμος του εξαμινου πχ 1ο εξαμηνο
    string start_of_semester , end_of_semester; // αρχη του εξαμηνου, τελος του εξαμηνου
    int number_of_lessons; //αριθμος μαθηματων 
public:
    Semester(int number_of_semester , string start_of_semester , string end_of_semester);
    void display(); // εμφανηση πληροφοριων για το εξαμηνο
    ~Semester();
};

#endif