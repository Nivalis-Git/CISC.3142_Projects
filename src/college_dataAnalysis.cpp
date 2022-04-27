#include "college.h"


namespace lab3 {




namespace college {




// Prints the pass rate for each course taught by an instructor, for a set of instructors.
void College::passRate_per_instructor(FILE *fp, std::set<Instructor> instructors)
{
	std::vector<std::string> grades; // container to be reused for holding grades
	
	// Iterating through all the instructors
	for (auto it = instructors.begin(); it != instructors.end(); it++)
	{
		fprintf(fp, "Instructor: %s\n%*s\n", it->id.c_str(), printWidth, "Pass Rates");
		
		std::set<Course> courses = get_instructorCourseSet(*it);  // Set of all courses taught by the instructor
		std::set<int> crsNums = get_courseNumberSet(courses);  // Set of all course numbers taught by the instructor
		
		// Iterating through the course numbers taught by the specific instructor
		for (auto itr = crsNums.begin(); itr != crsNums.end(); itr++)
		{
			collect_courseGrades(courses, grades, *itr);  // collect only the grades in *itr numbered courses
			fprintf(fp, "%*d:  %.2f\n", printWidth, *itr, passRate(grades));
			grades.clear();
		}
		
		collect_courseGrades(courses, grades);  // collect the grades from all the classes taught
		fprintf(fp, "%*s:  %.2f\n", printWidth, "Overall Pass Rate", passRate(grades));
		grades.clear();
		
		fprintf(fp, "\n\n");
	}
}

// Prints the pass rate for each course, for a set of courses
void College::passRate_per_courseNum(FILE *fp, std::set<Course> courses)
{
	fprintf(fp, "Course Pass Rates\n");
	
	std::vector<std::string> grades;
	std::set<int> crsNums = get_courseNumberSet(courses);
	for (auto it = crsNums.begin(); it != crsNums.end(); it++)
	{
		collect_courseGrades(courses, grades, *it);
		fprintf(fp, "%*d:  %.2f\n", printWidth, *it, passRate(grades));
		grades.clear();
	}
}

// Prints the withdraw rate for each course taught by an instructor, for a set of instructors.
void College::withdrawRate_per_instructor(FILE *fp, std::set<Instructor> instructors)
{
	const int printWidth {College::printWidth+5};
	std::vector<std::string> grades; // container to be reused for holding grades
	
	// Iterating through all the instructors
	for (auto it = instructors.begin(); it != instructors.end(); it++)
	{
		fprintf(fp, "Instructor: %s\n%*s\n", it->id.c_str(), printWidth, "Withdraw Rates");
		
		std::set<Course> courses = get_instructorCourseSet(*it);  // Set of all courses taught by the instructor
		std::set<int> crsNums = get_courseNumberSet(courses);  // Set of all course numbers taught by the instructor
		
		// Iterating through the course numbers taught by the specific instructor
		for (auto itr = crsNums.begin(); itr != crsNums.end(); itr++)
		{
			collect_courseGrades(courses, grades, *itr);  // collect only the grades in *itr numbered courses
			fprintf(fp, "%*d:  %.2f\n", printWidth, *itr, withdrawRate(grades));
			grades.clear();
		}
		
		collect_courseGrades(courses, grades);  // collect the grades from all the classes taught
		fprintf(fp, "%*s:  %.2f\n", printWidth, "Overall Withdraw Rate", withdrawRate(grades));
		grades.clear();
		
		fprintf(fp, "\n\n");
	}
}

// Prints the withdraw rate for each course, for a set of courses
void College::withdrawRate_per_courseNum(FILE *fp, std::set<Course> courses)
{
	fprintf(fp, "Course Withdraw Rates\n");
	
	const int printWidth {College::printWidth+5};
	
	std::vector<std::string> grades;
	std::set<int> crsNums = get_courseNumberSet(courses);
	for (auto it = crsNums.begin(); it != crsNums.end(); it++)
	{
		collect_courseGrades(courses, grades, *it);
		fprintf(fp, "%*d:  %.2f\n", printWidth, *it, withdrawRate(grades));
		grades.clear();
	}
}

void College::termPassRate_per_courseNum(FILE *fp, std::set<Course> courses, std::string term)
{
	fprintf(fp, "%s Pass Rates per Course Number\n", term.c_str());
	
	std::vector<std::string> grades;
	std::set<int> crsNums = get_courseNumberSet(courses);
	for (auto it = crsNums.begin(); it != crsNums.end(); it++)
	{
		collect_courseGrades(courses, grades, *it, term);
		fprintf(fp, "%*d:    %.2f\n", printWidth, *it, passRate(grades));
		grades.clear();
	}
}




}  // end of college namespace




}  // end of lab3 namespace
