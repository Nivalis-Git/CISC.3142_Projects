#ifndef LAB3_SRC_COLLEGE_STRUCTS_H_
#define LAB3_SRC_COLLEGE_STRUCTS_H_


#include <cstring>
#include <set>
#include <map>
#include <vector>


namespace college {

namespace struct_space {

struct Instructor
{
	char *id;
	Instructor(char *id);
	
	bool operator ==(const Instructor &other) const;
	bool operator <(const Instructor &other) const;
};

struct Student
{
	char *id;
	Student(char *id);
	
	bool operator ==(const Student &other) const;
	bool operator <(const Student &other) const;
};

struct Course
{
	int crs_num;
	char *term;
	char *section;
	char *instructor_id;
	Course(int crs_num, char *term, char *section, char *instructor_id);
	
	bool operator ==(const Course &other) const;
	bool operator <(const Course &other) const;
};

struct EnrollHistory
{
		EnrollHistory();
		
		std::set< std::pair<struct Course, struct Student> > enrollment;
		std::map< struct Course, std::vector<std::pair<struct Student, char*>> > courseRoster;
		std::map< struct Student, std::vector<std::pair<struct Course, char*>> > studentHistory;
		
		bool insert(struct Course course, std::pair<struct Student, char*> pr);
		
		private:
			void insert(struct Student student, std::pair<struct Course, char*> pr);
};

}  // end of structs namespace

}  // end of college namespace

#endif  // LAB3_SRC_COLLEGE_STRUCTS_H_
