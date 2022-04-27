#include "college.h"


namespace lab3 {


namespace college {


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

void College::print_studentRoster(FILE *fp)
{
	fprintf(fp, "Student Count: %d\n", student_roster.size());
	
	for (auto it = student_roster.begin(); it != student_roster.end(); it++)
	{
		fprintf(fp, "%*s\n", printWidth, (*it).id.c_str());
	}
}

void College::print_instructorRoster(FILE *fp)
{
	fprintf(fp, "Instructor Count: %d\n", instructor_roster.size());
	
	for (auto it = instructor_roster.begin(); it != instructor_roster.end(); it++)
	{
		fprintf(fp, "%*s\n", printWidth, (*it).id.c_str());
	}
}

void College::print_courseHistory(FILE *fp)
{
	fprintf(fp, "Class Count: %d\n", course_history.size());
	
	for (auto it = course_history.begin(); it != course_history.end(); it++)
	{
		fprintf(fp, "%*d    %s    %s    %s\n", printWidth,
			(*it).crs_num, (*it).term.c_str(), (*it).section.c_str(),
			(*it).instructor_id.c_str());
	}
}

void College::print_courseRoster(FILE *fp, Course crs)
{
	fprintf(fp, "Class:    %d    %s    %s    %s\n", crs.crs_num, crs.term.c_str(), crs.section.c_str(), crs.instructor_id.c_str());
	
	std::vector<std::pair<Student, std::string>> roster = get_courseRoster(crs);
	for (auto pr : roster)
	{
		fprintf(fp, "%*s    %s\n", printWidth, pr.first.id.c_str(), pr.second.c_str());
	}
}

void College::print_studentHistory(FILE *fp, Student stud)
{
	fprintf(fp, "Student: %s\n", stud.id.c_str());
	
	std::vector<std::pair<Course, std::string>> history = get_studentHistory(stud);
	for (auto pr : history)
	{
		fprintf(fp, "%*d    %s    %s    %s    %s\n", printWidth, pr.first.crs_num, pr.first.term.c_str(), pr.first.section.c_str(), pr.first.instructor_id.c_str(), pr.second.c_str());
	}
}


}  // end of college namespace


}  // end of lab3 namespace
