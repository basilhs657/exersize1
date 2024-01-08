#include "person.h"
#include "professor.h"
#include "student.h"
#include "course.h"

using namespace std;

#include <map>

class Secretary
{
    private:
        // map<string, Person *> person_map ; //USING A MAP TO ASSIGHN A KEY (DOCUMENT VALUE) TO FIND A PERSON OBJECT
        // map<string , Person *> extended_identificator; // USING A MAP TO ASSIGHN A KEY(FIRST NAME , LAST NAME , EMAIL) TO FIND A PERSON OBJECT
        map<Course *, Professor *> Course_Professor ;//key:courses  name , value :professor
        map<Student * ,Course*>   Course_Sudent ;//each course student can join 
        map<Professor * , pair<int ,Student *> > Professor_Student ; //each teacher gives a grade  for each student



    public:
        Secretary();

        // Secretary& operator+(Person& person);

        // friend istream & operator>>(istream & input ,Secretary& sec);

        friend ostream& operator<<(ostream& output,const Secretary& sec);

        // Secretary& operator=(const Secretary& sec);

        Secretary(const Secretary& other);

        // void Find_with_doc_number();

        // void findUsingData();

        ~Secretary();


};