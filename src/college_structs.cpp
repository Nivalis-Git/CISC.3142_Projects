#include "college_structs.h"


namespace college {

namespace struct_space {

Instructor::Instructor(std::string &id) :
	id{id} {}

bool Instructor::operator ==(const Instructor &other) const
{
	return std::tie(this->id) == std::tie(other.id);
}

bool Instructor::operator <(const Instructor &other) const
{
	return std::tie(this->id) < std::tie(other.id);
}


Student::Student(std::string &id) :
	id{id} {}

bool Student::operator ==(const Student &other) const
{
	return std::tie(this->id) == std::tie(other.id);
}

bool Student::operator <(const Student &other) const
{
	return std::tie(this->id) < std::tie(other.id);
}


Course::Course(int crs_num, std::string &term, std::string &section, std::string &instructor_id) :
	crs_num{crs_num}, term{term}, section{section}, instructor_id{instructor_id} {}

bool Course::operator ==(const Course &other) const
{
	return std::tie(this->crs_num, this->term, this->section) == std::tie(other.crs_num, other.term, other.section);
}

bool Course::operator <(const Course &other) const
{
	return std::tie(this->crs_num, this->term, this->section) < std::tie(other.crs_num, other.term, other.section);
}


EnrollHistory::EnrollHistory()
{
}

bool EnrollHistory::insert(struct Course course, std::pair<struct Student, std::string> pr)
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
			std::vector<std::pair<struct Student, std::string>> v {pr};
			courseRoster.insert({course, v});
		}
		std::pair<struct Course, std::string> test {course, pr.second};
		insert(pr.first, {course,pr.second});
		return true;
	}
	else
	{
		return false;
	}
}

void EnrollHistory::insert(struct Student student, std::pair<struct Course, std::string> pr)
{
	auto roster = studentHistory.find(student);
	if (roster != studentHistory.end())
	{
		(roster->second).push_back(pr);
	}
	else
	{
		std::vector<std::pair<struct Course, std::string>> v {pr};
		studentHistory.insert({student, v});
	}
}

}  // end of struct_space namespoace

}  // end of college namespace
