#include "college.h"


namespace lab3 {




namespace college {




/*    Reading    */
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




/*    Writing    */
void College::print_studentSet(FILE *fp, std::set<Student> students)
{
	fprintf(fp, "Student Count: %d\n", students.size());
	
	for (auto it = students.begin(); it != students.end(); it++)
	{
		fprintf(fp, "%*s\n", printWidth, (*it).id.c_str());
	}
}

void College::print_instructorSet(FILE *fp, std::set<Instructor> instructors)
{
	fprintf(fp, "Instructor Count: %d\n", instructors.size());
	
	for (auto it = instructors.begin(); it != instructors.end(); it++)
	{
		fprintf(fp, "%*s\n", printWidth, (*it).id.c_str());
	}
}

void College::print_courseSet(FILE *fp, std::set<Course> courses)
{
	fprintf(fp, "Class Count: %d\n", courses.size());
	
	for (auto it = courses.begin(); it != courses.end(); it++)
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

std::string College::timestamp()
{
	auto now = std::chrono::system_clock::now();
	//auto UTC = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();

	auto in_time_t = std::chrono::system_clock::to_time_t(now);
	std::stringstream datetime;
	datetime << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

	// UTC
		//std::ofstream myFile1("report_" + std::to_string(UTC) + ".csv");
	return datetime.str();
}




}  // end of college namespace




}  // end of lab3 namespace
