#include "college.h"


namespace college {

namespace class_space {

void College::read(College college, char *filename)
{
	FILE* inFile = fopen(filename, "r");
	fscanf(inFile, "%*[^\n]\n");
	
	char *buffer = (char*)malloc(512 * sizeof(*buffer));
	while (fgetc(inFile) != '\n')
	{
	}
	
	char *line;
	while ( fscanf(inFile, "%[^\n]", line) == 1 )
	{
		parseLine(college, line);
	}
	
	fclose(inFile);
}

void College::parseLine(College college, char *data)
{
	char *student_id, *instructor_id, *term, *section, *grade;
	int crs_num;
	sscanf(data,"%[^,],%d,%[^,],%[^,],%[^,],%[^\n]", student_id, &crs_num, instructor_id, term, section, grade);
	
	Student stud = Student(student_id);
	Instructor instr = Instructor(instructor_id);
	Course crs = Course(crs_num, term, section, instructor_id);
	
	student_roster.insert(stud);
	instructor_roster.insert(instr);
	course_history.insert(crs);
	enroll_history.insert(crs, {stud, grade});
}

}  // end of class_space namespace

}  // end of college namespace
