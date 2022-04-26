#include "college.h"


namespace college {

namespace class_space {

void College::list()
{
	std::cout << "\n" << "Students" << "\n";
	
	std::set<Student>::iterator it;
	for (it = student_roster.begin(); it != student_roster.end(); it++)
	{
		std::cout << "\t" << (*it).id << "\n";
	}
}

} // end of class_space namespace

} // end of college namespace
