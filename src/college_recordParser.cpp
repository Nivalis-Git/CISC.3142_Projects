#include "college.h"


namespace college {

namespace class_space {

void College::read(College college, char *filename)
{
	std::ifstream inFile(filename, std::ios::in);
	std::string line {};
	getline(inFile, line);
	
	while ( inFile.peek() != EOF )
	{
		getline(inFile, line);
		parseLine(college, line);
	}
	
	inFile.close();
}

void College::parseLine(College college, std::string data)
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
