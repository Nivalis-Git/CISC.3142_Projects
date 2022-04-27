#include "college.h"


int main(int argc, char *argv[])
{
	using namespace lab3::college;
	College college;
	
	for (int i = 1; i < argc; i++)
	{
		college.read(argv[i]);
	}
	
	FILE *outFile = fopen("analysis.txt", "w");
	college.print_studentRoster(outFile);
	college.print_instructorRoster(outFile);
	college.print_courseHistory(outFile);
	
	// printing every course roster
	auto courseHistory = college.get_courseHistory();
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
	auto studentRoster = college.get_studentRoster();
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
