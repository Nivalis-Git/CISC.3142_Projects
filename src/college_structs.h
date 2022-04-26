#ifndef LAB3_SRC_COLLEGE_STRUCTS_H_
#define LAB3_SRC_COLLEGE_STRUCTS_H_


#include <string>
#include <set>
#include <map>
#include <vector>


namespace college {

namespace struct_space {

struct Instructor
{
	std::string id;
	Instructor(std::string &id);
	
	bool operator ==(const Instructor &other) const;
	bool operator <(const Instructor &other) const;
};

struct Student
{
	std::string id;
	Student(std::string &id);
	
	bool operator ==(const Student &other) const;
	bool operator <(const Student &other) const;
};

struct Course
{
	int crs_num;
	std::string term;
	std::string section;
	std::string instructor_id;
	Course(int crs_num, std::string &term, std::string &section, std::string &instructor_id);
	
	bool operator ==(const Course &other) const;
	bool operator <(const Course &other) const;
};

struct EnrollHistory
{
		EnrollHistory();
		
		std::set< std::pair<struct Course, struct Student> > enrollment;
		std::map< struct Course, std::vector<std::pair<struct Student, std::string>> > courseRoster;
		std::map< struct Student, std::vector<std::pair<struct Course, std::string>> > studentHistory;
		
		bool insert(struct Course course, std::pair<struct Student, std::string> pr);
		void insert(struct Student student, std::pair<struct Course, std::string> pr);
};

}  // end of structs namespace

}  // end of college namespace

#endif  // LAB3_SRC_COLLEGE_STRUCTS_H_
