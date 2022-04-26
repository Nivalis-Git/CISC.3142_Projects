#include "college.h"


namespace college {

namespace class_space {

void College::read(char *filename)
{
	std::ifstream inFile(filename, std::ios::in);
	std::string line{};
	getline(inFile, line);
	
	while ( inFile.peek() != EOF )
	{
		getline(inFile, line);
		parseLine(line);
	}
	
	inFile.close();
}

void College::parseLine(std::string &data)
{
	std::string student_id, crs_temp, instructor_id, term, section, grade;
	std::stringstream ss{data};
	
	getline(ss, student_id, ',');
	getline(ss, crs_temp, ',');
		int crs_num{std::stoi(crs_temp)};
	getline(ss, instructor_id, ',');
	getline(ss, term, ',');
	getline(ss, section, ',');
	getline(ss, grade, '\n');
	
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
