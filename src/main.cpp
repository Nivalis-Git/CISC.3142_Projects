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
	
	
	std::string filename {"../output/"};
		filename.append(College::timestamp());
		filename.append("_prate-per-instr.txt");
	FILE *outFile = fopen(filename.c_str(), "w");
	
	
	
	
	
	fclose(outFile);
	return 0;
}
