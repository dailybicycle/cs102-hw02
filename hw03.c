#include <stdio.h>
#include <stdlib.h> //Added this for atoi

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major; //RTC: Added
  int  year; //RTC: Added; chose int because of comments below. No need for ptr.
  // TODO: add fields here for major and year : DONE
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
    	printf("%s %s\n", s.first_name, s.last_name);
    	break;
    case MAJOR_AND_NAME:
   		printf("%s %s %s\n", s.major, s.first_name, s.last_name);
    	break;
    case YEAR_AND_NAME:
    	printf("%d %s %s\n", s.year, s.first_name, s.last_name); //%d is for int of year.
    	break;	
  // TODO: handle other cases : DONE
  }
}

/*
argv[1] will be the Mode integer.
argv[2]-argv[5] will be student info in the form [first_name, last_name, major, year].
argv[6]-argv[9], if present will be student info for a second student in the same form, and so on.
You will need to check argc to determine the number of students passed at runtime.
The fields are all strings (char[]), except year is a number (int)
*/
int main(int argc, char **argv) {
	int mode = atoi(argv[1]); //grabs first input in argv after program name and makes it an int to use later in print_student.

for(int i=2; i < argc; i+=4) //after mode, first element of Student struct is at 2. Every 4 inputs is the beginning of new Student.
							 //initialized right in for expression for neatness. argc is just # of entries in argv[], so that's the max # of entries.
							 //+= is same as i=i+4, increment by 4.
{
	Student stewie;
	stewie.first_name = argv[i];
	stewie.last_name  = argv[i+1];
	stewie.major 	   = argv[i+2];
	stewie.year 	   = atoi(argv[i+3]); //change back to int
 	print_student(mode, stewie);
}
	
	// TODO: parse argv to populate student structs 
	  // for now, here's two hardcoded students:
	  //Student s1, s2;
	  //s1.first_name = "Julia";
	  //s1.last_name = "A";
	  //s2.first_name = "Peter";
	  //s2.last_name = "Cooper";
  
 
  return 0;
}
