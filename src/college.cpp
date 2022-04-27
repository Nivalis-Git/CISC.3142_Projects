#include "college.h"


namespace lab3 {




namespace college {




/*    Get Methods    */
std::set<Student> College::get_studentRoster()
{
	return student_roster;
}

std::set<Instructor> College::get_instructorRoster()
{
	return instructor_roster;
}

std::set<Course> College::get_courseHistory()
{
	return course_history;
}

std::vector<std::pair<Student, std::string>> College::get_courseRoster(Course crs)
{
	return enroll_history.get_courseRoster(crs);
}

std::vector<std::pair<Course, std::string>> College::get_studentHistory(Student stud)
{
	return enroll_history.get_studentHistory(stud);
}




/*    Derived Get methods    */

// Get a set of all unique course numbers within a set of courses
std::set<int> College::get_courseNumberSet(std::set<Course> courses)
{
	std::set<int> crsNumbers;
	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		crsNumbers.insert(it->crs_num);
	}
	return crsNumbers;
}

// Get a set of all courses taught by a given instructor
std::set<Course> College::get_instructorCourseSet(Instructor instr)
{
	std::set<Course> instrCourses;
	std::set<Course> courseHistory = get_courseHistory();
	for (auto it = courseHistory.begin(); it != courseHistory.end(); it++)
	{
		if (instr.id == it->instructor_id)
		{
			instrCourses.insert(*it);
		}
	}
	return instrCourses;
}




/*    Collection Methods    */

// Collect grades from a student
void College::collect_studentGrades(Student stud, std::vector<std::string> &grades)
{
	std::vector<std::pair<Course, std::string>> history = get_studentHistory(stud);
	
	for (auto it = history.begin(); it != history.end(); it++)
	{
		grades.push_back(it->second);
	}
}

// Collect grades from a set of students
void College::collect_studentGrades(std::set<Student> students, std::vector<std::string> &grades)
{
	for (auto it = students.begin(); it != students.end(); it++)
	{
		collect_studentGrades(*it, grades);
	}
}

// Collect grades from a course
void College::collect_courseGrades(Course crs, std::vector<std::string> &grades)
{
	std::vector<std::pair<Student, std::string>> roster = get_courseRoster(crs);
	
	for (auto it = roster.begin(); it != roster.end(); it++)
	{
		grades.push_back(it->second);
	}
}

// Collect grades from a set of courses
void College::collect_courseGrades(std::set<Course> courses, std::vector<std::string> &grades)
{
	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		collect_courseGrades(*it, grades);
	}
}

// Collect grades from a set of courses but only from those that match the given criteria
void College::collect_courseGrades(std::set<Course> courses, std::vector<std::string> &grades, int crs_num)
{
	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		if (it->crs_num == crs_num)
		{
			collect_courseGrades(*it, grades);
		}
	}
}

// Collect grades from a set of courses but only from those that match the given criteria
void College::collect_courseGrades(std::set<Course> courses, std::vector<std::string> &grades, int crs_num, std::string term_id)
{
	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		if (it->crs_num == crs_num && it->term_id == term_id)
		{
			collect_courseGrades(*it, grades);
		}
	}
}




/*    Insertion Methods     */

bool College::register_student(Student stud)
{
	return student_roster.insert(stud).second;
}

bool College::register_instructor(Instructor instr)
{
	return instructor_roster.insert(instr).second;
}

bool College::register_course(Course crs)
{
	return course_history.insert(crs).second;
}

bool College::register_term(std::string term_id)
{

	if (fall(term_id))
	{
		Term term{"Fall"};
		std::set<std::string> termID_set {term_id};
		
		auto pr = terms.insert({term, termID_set});
		if ( !pr.second )
		{
			if ( (pr.first)->second.insert(term_id).second )
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		return true;
	}
	
	else if (spring(term_id))
	{
		Term term{"Spring"};
		std::set<std::string> termID_set {term_id};
		
		auto pr = terms.insert({term, termID_set});
		if ( !pr.second )
		{
			if ( (pr.first)->second.insert(term_id).second )
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		return true;
	}
	
	else
	{
		return false;
	}
	
}




/*    Checks and Tests    */

bool College::pass(std::string grade)
{
	bool pass = ( grade == "A+" || grade == "A" || grade == "A-" 
		|| grade == "B+" || grade == "B" || grade == "B-" 
		|| grade == "C+" || grade == "C" || grade == "C-");
	
	if (pass) {return true;}
	else {return false;}
}

bool College::fail(std::string grade)
{
	bool fail = (grade == "D+" || grade == "D" || grade == "D-" || grade == "F" || grade == "INC");
	
	if (fail) {return true;}
	else {return false;}
}

bool College::withdraw(std::string grade)
{
	bool withdraw = (grade == "W" || grade == "WU" || grade == "WD" || grade == "WN");
	
	if (withdraw) {return true;}
	else {return false;}
}

bool College::fall(std::string term_id)
{
	bool fall = (term_id == "T04" || term_id == "T08" || term_id == "T12" || term_id == "T16" || term_id == "T20" || term_id == "T23");
	
	if (fall) {return true;}
	else {return false;}
}

bool College::spring(std::string term_id)
{
	bool spring = (term_id == "T02" || term_id == "T06" || term_id == "T10" || term_id == "T14" || term_id == "T18" || term_id == "T21");
	
	if (spring) {return true;}
	else {return false;}
}




/*    Stats and Counting    */

float College::passRate(std::vector<std::string> &grades)
{
	float passCount {0};
	for (std::string grade : grades)
	{
		if (pass(grade))
		{
			passCount++;
		}
	}
	
	return (passCount/grades.size() * 100);
}

float College::withdrawRate(std::vector<std::string> &grades)
{
	float wCount {0};
	for (std::string grade : grades)
	{
		if (withdraw(grade))
		{
			wCount++;
		}
	}
	
	return (wCount/grades.size() * 100);
}




} // end of class_space namespace




} // end of college namespace
