#include "person.h"
#include "secretary.h"
#include "student.h"
#include "professor.h"

int main(){

	Secretary secretary;
	Professor professor("1" , "2" , 3 , "4" , "5" ,6 , 5 , "f3");
	Student bill("bill" , "tzimp" , 12 , "sdsdsd" , "hello@"," AM" , 10 , 10);
	
	return 0;
}
