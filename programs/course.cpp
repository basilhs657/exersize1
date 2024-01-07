<<<<<<< HEAD
#include "course.h"

Course:: Course(bool needed , string name , int points ): needed(needed), name(name ) , points(points){}; 
void Course::SetName(string name ){name =name;};
void Course::SetNeeded(string if_needed){
    if(if_needed=="yes") needed=true;
    else needed=false;
}
void Course::SetPoints(int points ){points=points;};
Course::~Course(){};