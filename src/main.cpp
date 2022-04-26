#include "college.h"


int main(int argc, char *argv[])
{
	using namespace college::class_space;
	College college;
	
	for (int i = 1; i < argc; i++)
	{
		college.read(argv[i]);
	}
	
	college.list();
	return 0;
}
