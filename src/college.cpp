#include "college.h"


namespace college {

namespace class_space {

void College::list()
{
	std::cout << "\n" << "Students: " << student_roster.size() << "\n";
	for (auto it = student_roster.begin(); it != student_roster.end(); it++)
	{
		std::cout << "\t" << (*it).id << "\n";
	}
	
	
	std::cout << "\n" << "Instructors: " << instructor_roster.size() << "\n";
	for (auto it = instructor_roster.begin(); it != instructor_roster.end(); it++)
	{
		std::cout << "\t" << (*it).id << "\n";
	}
	
	
	std::cout << "\n" << "Courses: " << course_history.size() << "\n";
	for (auto it = course_history.begin(); it != course_history.end(); it++)
	{
		std::cout << "\t" << (*it).crs_num << "\t" << (*it).term << "\t" << (*it).section << "\t" << (*it).instructor_id << "\n";
	}
}

} // end of class_space namespace

} // end of college namespace
