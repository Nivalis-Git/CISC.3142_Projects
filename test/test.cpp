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
	
	
	FILE *outFile = fopen("analysis.txt", "w");
	
	std::set<Student> studentRoster = college.get_studentRoster();
	std::set<Instructor> instructorRoster = college.get_instructorRoster();
	std::set<Course> courseHistory = college.get_courseHistory();
	
	college.print_studentSet(outFile, studentRoster);
	college.print_instructorSet(outFile, instructorRoster);
	college.print_courseSet(outFile, courseHistory);
	
	
	// print all instructor course sets
	for (auto it = instructorRoster.begin(); it != instructorRoster.end(); it++)
	{
		fprintf(outFile, "Instructor: %s    ", it->id.c_str());
		college.print_courseSet(outFile, college.get_instructorCourseSet(*it));
	}
	
	
	// printing all unique course numbers
	std::set<int> courseNumbers = college.get_courseNumSet(courseHistory);
	for (auto it = courseNumbers.begin(); it != courseNumbers.end(); it++)
	{
		fprintf(outFile, "%d    ", *it);
	}
	fprintf(outFile, "\n");
	
	
	
	// printing every course roster
	for (auto it = courseHistory.begin(); it != courseHistory.end(); it++)
	{
		college.print_courseRoster(outFile, *it);
		
		std::vector<std::string> courseGrades;
		college.collect_courseGrades(*it, courseGrades);
		for (std::string grade : courseGrades)
		{
			fprintf(outFile, "%s    ", grade.c_str());
		}
		fprintf(outFile, "\n");
	}
	
	
	// printing every student history
	for (auto it = studentRoster.begin(); it != studentRoster.end(); it++)
	{
		college.print_studentHistory(outFile, *it);
		
		std::vector<std::string> studentGrades;
		college.collect_studentGrades(*it, studentGrades);
		for (std::string grade : studentGrades)
		{
			fprintf(outFile, "%s    ", grade.c_str());
		}
		fprintf(outFile, "\n");
	}
	
	
	fclose(outFile);
	return 0;
}
