#ifndef LAB3_SRC_COLLEGE_STRUCTS_H_
#define LAB3_SRC_COLLEGE_STRUCTS_H_


#include <string>
#include <set>
#include <map>
#include <vector>


namespace lab3 {




namespace college_structs {




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
		
		std::set< std::pair<struct Course, struct Student> > enrollment;  // Ensures no duplicate enrollment records exist
		std::map< struct Course, std::vector<std::pair<struct Student, std::string>> > course_roster;
		std::map< struct Student, std::vector<std::pair<struct Course, std::string>> > student_history;		
		
		std::vector<std::pair<Student, std::string>> get_courseRoster(Course crs);
		std::vector<std::pair<Course, std::string>> get_studentHistory(Student stud);
		
		bool insert(struct Course course, std::pair<struct Student, std::string> pr);
		void insert(struct Student student, std::pair<struct Course, std::string> pr); // Called in the other insert method
};




}  // end of college_structs namespace




}  // end of lab3 namespace


#endif  // LAB3_SRC_COLLEGE_STRUCTS_H_
