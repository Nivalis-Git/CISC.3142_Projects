#include "college.h"


namespace college {

namespace class_space {

void College::read(College college, char *filename)
{
	FILE *inFile = fopen(filename, "r");
	endOfLine(inFile);
	
	//char *line, *buffer;
	//int buflen = 512 * sizeof(*buffer);
	//buffer = (char*)malloc(buflen);
	//line = (char*)malloc(buflen);
	//fpos_t *fpos;
	while (*line != EOF)
	{
		//fgetpos(inFile, fpos);
		//int size = get_lineSize(inFile, buffer, buflen);
		//line = (char*)realloc(line, size * sizeof(*line) + 1);
		//fsetpos(inFile, fpos);
		
		fscanf(inFile, "%[^\n]", line);
		parseLine(college, line, size);
	}
	
	free(line);
	free(buffer);
	fclose(inFile);
}

void College::parseLine(College college, char *data, int size)
{
	char student_id[size], instructor_id[size], term[size], section[size], grade[size];
	int crs_num;
	sscanf(data,"%[^,],%d,%[^,],%[^,],%[^,],%[^\n]", student_id, &crs_num, instructor_id, term, section, grade);
	
	Student stud = Student(student_id);
	Instructor instr = Instructor(instructor_id);
	Course crs = Course(crs_num, term, section, instructor_id);
	
	student_roster.insert(stud);
	instructor_roster.insert(instr);
	course_history.insert(crs);
	enroll_history.insert(crs, {stud, grade});
}

int College::get_lineSize(FILE *fp, char *buffer, size_t buflen)
{
	char *end = buffer + buflen - 1;  //Allow space for null terminator
	char *dst = buffer;
	
	int c;
	while ( (c = fgetc(fp)) != EOF && c != '\n' && dst < end )
	{
		*dst++ = c;
	}
	
	*dst = '\0';
	return( (c == EOF && dst == buffer) ? EOF : dst - buffer );
}

void College::endOfLine(FILE *fp)
{
	int c = fgetc(fp);
	do {c = fgetc(fp);} while (c != '\n');
}

}  // end of class_space namespace

}  // end of college namespace
