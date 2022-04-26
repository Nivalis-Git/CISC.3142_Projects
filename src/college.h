#ifndef LAB3_SRC_COLLEGE_H_
#define LAB3_SRC_COLLEGE_H


#include <iostream>
#include "college_structs.h"


namespace college {

namespace class_space {

class College
{
	private:
		typedef college::struct_space::Instructor Instructor;
		typedef college::struct_space::Student Student;
		typedef college::struct_space::Course Course;
		typedef college::struct_space::EnrollHistory EnrollHistory;
		
		std::set<Instructor> instructor_roster;
		std::set<Student> student_roster;
		std::set<Course> course_history;
		EnrollHistory enroll_history{};
		
		void parseLine(College college, char *fp, int size);
		void endOfLine(FILE *fp);
		int get_lineSize(FILE *fp, char *buffer, size_t buflen);
	
	public:
		void read(College college, char *filename);
		void list();
};

} // end of class_space namespace

} // end of college namespace

#endif  // LAB3_SRC_COLLEGE_H_
