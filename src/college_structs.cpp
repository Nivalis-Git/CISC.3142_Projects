#include "college_structs.h"


namespace lab3 {




namespace college_structs {




/*    Instructor    */
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




/*    Student    */
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




/*    Course    */
Course::Course(int crs_num, std::string &term_id, std::string &section, std::string &instructor_id) :
	crs_num{crs_num}, term_id{term_id}, section{section}, instructor_id{instructor_id} {}

bool Course::operator ==(const Course &other) const
{
	return std::tie(this->crs_num, this->term_id, this->section) == std::tie(other.crs_num, other.term_id, other.section);
}

bool Course::operator <(const Course &other) const
{
	return std::tie(this->crs_num, this->term_id, this->section) < std::tie(other.crs_num, other.term_id, other.section);
}




/*    Term    */
Term::Term(std::string name) : name{name} {}

bool Term::insert_id(std::string term_id)
{
	return id_set.insert(term_id).second;
}

std::set<std::string> Term::get_id_set()
{
	return id_set;
}




/*    EnrollHistory    */
EnrollHistory::EnrollHistory()
{
}

bool EnrollHistory::insert(struct Course course, std::pair<struct Student, std::string> pr)
{
	if ( enrollment.insert({course, pr.first}).second )
	{
		auto roster = course_roster.find(course);
		if (roster != course_roster.end())
		{
			(roster->second).push_back(pr);
		}
		else
		{
			std::vector<std::pair<struct Student, std::string>> v {pr};
			course_roster.insert({course, v});
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
	auto roster = student_history.find(student);
	if (roster != student_history.end())
	{
		(roster->second).push_back(pr);
	}
	else
	{
		std::vector<std::pair<struct Course, std::string>> v {pr};
		student_history.insert({student, v});
	}
}

std::vector<std::pair<Student, std::string>> EnrollHistory::get_courseRoster(Course crs)
{
	return course_roster.find(crs)->second;
}

std::vector<std::pair<Course, std::string>> EnrollHistory::get_studentHistory(Student stud)
{
	return student_history.find(stud)->second;
}




}  // end of college_structs namespoace




}  // end of lab3 namespace
