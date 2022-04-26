#ifndef LAB3_SRC_COLLEGE_H_
#define LAB3_SRC_COLLEGE_H


#include <fstream>
#include <string>

#include "college_structs.h"


namespace college {

namespace class_space {

class College
{
	typedef college::struct_space::Instructor Instructor;
	typedef college::struct_space::Student Student;
	typedef college::struct_space::Course Course;
	typedef college::struct_space::EnrollHistory EnrollHistory;
	
	std::set<Instructor> instructor_roster;
	std::set<Student> student_roster;
	std::set<Course> course_history;
	EnrollHistory enroll_history{};
	
	public:
		void read(College college, char *filename);
		void parseLine(College college, std::string data);
};

} // end of class_space namespace

} // end of college namespace

#endif  // LAB3_SRC_COLLEGE_H_
