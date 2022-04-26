#include "college.h"


namespace college {

namespace class_space {

void College::read(College &college, char *filename)
{
	std::ifstream inFile(filename, std::ios::in);
	std::string line{};
	getline(inFile, line);
	
	while ( inFile.peek() != EOF )
	{
		getline(inFile, line);
		parseLine(college, line);
	}
	
	inFile.close();
}

void College::parseLine(College &college, std::string &data)
{
	//sscanf(data.c_str(),"%[^,],%d,%[^,],%[^,],%[^,],%[^\n]", student_id.c_str(), &crs_num, instructor_id.c_str(), term.c_str(), section.c_str(), grade.c_str());
	
	std::string::size_type pos1 = data.find(","), pos2 = data.find(",", pos1+1),
		pos3 = data.find(",", pos2+1), pos4 = data.find(",", pos3+1),
		pos5 = data.find(",", pos4+1);
	int crs_num { std::stoi( data.substr(pos1+1, pos2-(pos1+1)) ) };
	std::string
		student_id { data.substr(0, pos1) },
		instructor_id { data.substr(pos2+1, pos3-(pos2+1)) },
		term { data.substr(pos3+1, pos4-(pos3+1)) },
		section { data.substr(pos4+1, pos5-(pos4+1)) },
		grade { data.substr(pos5+1) };
	
	/*
	std::stringstream ss{data};
	getline(ss, student_id, ',');
	getline(ss, crs_num, ',');
	getline(ss, instructor_id, ',');
	getline(ss, term, ',');
	getline(ss, section, ',');
	getline(ss, grade, '\n');
	*/
	
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
