#ifndef COURSE_H
#define COURSE_H
using namespace std;
#include <string>

class Course
{
    string name ; 
    bool needed; //einai ypoxreotiko 
    int points;

public:
    Course(bool needed , string name , int point); 
    void SetName(string name );
    void SetPoints(int points);
    void SetNeeded(string if_needed);
    ~Course();
};

=======
#ifndef COURSE_H
#define COURSE_H

class Course
{
    string name ; 
    bool needed; //einai ypoxreotiko 
    int points;

public:
    Course(bool needed , string name , int points ); 
    void SetName(string name ) ;
    void SetPoints(int points);
    void SetNeeded(string if_needed);
    ~Course();
};

>>>>>>> f258e5c157ab566d02324a9373235ed416a3f046
#endif