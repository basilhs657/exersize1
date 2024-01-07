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

#endif