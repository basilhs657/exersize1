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

#endif  