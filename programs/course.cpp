#include "course.h"

Course:: Course(bool needed , string name , int points ): needed(needed), name(name ) , points(points){}; 
Course::SetName(string name ){name=name;};
Course::SetNeeded(string if_needed){
    if(if_needed="yes") needed=true;
    else needed=false;
}
Course::SetNeeded(int points ){points=points;};