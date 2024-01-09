#include "person.h"
#include "secretary.h"
#include "student.h"
#include "professor.h"
#include "course.h"


int main(){
	Semester first_semester(1 , "10/10/23" , "1/1/24");
	Semester second_semester(2 , "2/1/24" , " 6/6/24");
	Secretary secretary;
	Professor professor("1" , "2" , 3 , "4" , "5" ,6 , 5 , "f3");
	Student bill("bill" , "tzimp" , 12 , "sdsdsd" , "hello@"," AM" , 10 , 10);
	Course course("Object oriented programming" , true , 8 , &first_semester);
	course.display();
	course.changeSemester(&second_semester);
	return 0;
}
