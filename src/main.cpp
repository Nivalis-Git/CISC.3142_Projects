#include "college.h"


int main(int argc, char *argv[])
{
	using namespace lab3::college;
	using namespace lab3::college_structs;
	
	
	College college;
	for (int i = 1; i < argc; i++)
	{
		college.read(argv[i]);
	}
	
	
// I. Pass rate per instructor (and per course)
	std::string filename {"../output/"};
		filename.append(College::timestamp());
		filename.append("_prate-per-instr.txt");
	FILE *outFile = fopen(filename.c_str(), "w");
	
	const int printWidth {17};
	std::vector<std::string> grades; // container to be reused for holding grades
	
	// Iterating through all the instructors
	std::set<Instructor> instructors = college.get_instructorRoster();
	for (auto it = instructors.begin(); it != instructors.end(); it++)
	{
		fprintf(outFile, "Instructor: %s\n%*s\n", it->id.c_str(), printWidth, "Pass Rates");
		
		std::set<Course> courses = college.get_instructorCourseSet(*it);  // Set of all courses taught by the instructor
		std::set<int> courseNumbers = college.get_courseNumberSet(courses);  // Set of all course numbers taught by the instructor
		
		// Iterating through the course numbers taught by the specific instructor
		for (auto itr = courseNumbers.begin(); itr != courseNumbers.end(); itr++)
		{
			college.collect_courseGrades(courses, grades, *itr);  // collect only the grades in *itr numbered courses
			fprintf(outFile, "%*d:  %.2f\n", printWidth, *itr, college.passRate(grades));
			grades.clear();
		}
		
		college.collect_courseGrades(courses, grades);  // collect the grades from all the classes taught
		fprintf(outFile, "%*s:  %.2f\n", printWidth, "Overall Pass Rate", college.passRate(grades));
		grades.clear();
		
		fprintf(outFile, "\n\n");
	}
	
	// Writing the pass rates per course number
	fprintf(outFile, "Course Pass Rates\n");
	
	std::set<Course> courseHistory = college.get_courseHistory();
	std::set<int> courseNumbers = college.get_courseNumberSet(courseHistory);
	for (auto it = courseNumbers.begin(); it != courseNumbers.end(); it++)
	{
		college.collect_courseGrades(courseHistory, grades, *it);
		fprintf(outFile, "%*d:  %.2f\n", printWidth, *it, college.passRate(grades));
		grades.clear();
	}
	
	fclose(outFile);


// II.


// III.
	
	
// IV. End of program
	return 0;
}
