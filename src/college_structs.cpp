#include "college_structs.h"


namespace college {

namespace struct_space {

Instructor::Instructor(char *id)
{
	this->id = id;
}

bool Instructor::operator ==(const Instructor &other) const
{
	return strcmp(this->id, other.id) == 0;
}

bool Instructor::operator <(const Instructor &other) const
{
	return strcmp(this->id, other.id) < 0;
}


Student::Student(char *id)
{
	this->id = id;
}

bool Student::operator ==(const Student &other) const
{
	return strcmp(this->id, other.id) == 0;
}

bool Student::operator <(const Student &other) const
{
	return strcmp(this->id, other.id) < 0;
}


Course::Course(int crs_num, char *term, char* section, char *instructor_id)
{
	this->crs_num = crs_num;
	this->term = term;
	this->section = section;
	this->instructor_id = instructor_id;
}

bool Course::operator ==(const Course &other) const
{
	return (this->crs_num == other.crs_num) && (strcmp(this->term, other.term) == 0) && (strcmp(this->section, other.section) < 0);
}

bool Course::operator <(const Course &other) const
{
	return (this->crs_num < other.crs_num) && (strcmp(this->term, other.term) < 0) && (strcmp(this->section, other.section) < 0);
}


EnrollHistory::EnrollHistory()
{
}

bool EnrollHistory::insert(struct Course course, std::pair<struct Student, char*> pr)
{
	if ( enrollment.insert({course, pr.first}).second )
	{
		auto roster = courseRoster.find(course);
		if (roster != courseRoster.end())
		{
			(roster->second).push_back(pr);
		}
		else
		{
			std::vector<std::pair<struct Student, char*>> v {pr};
			courseRoster.insert({course, v});
		}
		insert(pr.first, {course, pr.second});
		return true;
	}
	else
	{
		return false;
	}
}

void EnrollHistory::insert(struct Student student, std::pair<struct Course, char*> pr)
{
	auto roster = studentHistory.find(student);
	if (roster != studentHistory.end())
	{
		(roster->second).push_back(pr);
	}
	else
	{
		std::vector<std::pair<struct Course, char*>> v {pr};
		studentHistory.insert({student, v});
	}
}

}  // end of struct_space namespoace

}  // end of college namespace
