#include "college.h"


int main(int argc, char *argv[])
{
	using namespace college::class_space;
	College college;
	college.read(college, "test.csv");
	
	return 0;
}
