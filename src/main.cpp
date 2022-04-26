#include "college.h"


int main(int argc, char *argv[])
{
	using namespace college::class_space;
	College college;
	college.read(college, "../data/1115.csv");

	college.list();
	return 0;
}
