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
		filename.append("_passRate.txt");
	FILE *outFile = fopen(filename.c_str(), "w");
	
	college.passRate_per_instructor(outFile, college.get_instructorRoster());
	college.passRate_per_courseNum(outFile, college.get_courseHistory());
	
	fclose(outFile);


// II. Withdraw rate per instructor (and per course)
	filename.assign("../output/");
		filename.append(College::timestamp());
		filename.append("_withdrawRate.txt");
	outFile = fopen(filename.c_str(), "w");
	
	college.withdrawRate_per_instructor(outFile, college.get_instructorRoster());
	college.withdrawRate_per_courseNum(outFile, college.get_courseHistory());
	
	fclose(outFile);


// III. Fall vs Spring pass rate for each course
	filename.assign("../output/");
		filename.append(College::timestamp());
		filename.append("_fall-vs-spring.txt");
	outFile = fopen(filename.c_str(), "w");
	
	college.termPassRate_per_courseNum(outFile, college.get_courseHistory(), "Fall");
	college.termPassRate_per_courseNum(outFile, college.get_courseHistory(), "Spring");
	
	fclose(outFile);


// IV. End of program
	return 0;
}
