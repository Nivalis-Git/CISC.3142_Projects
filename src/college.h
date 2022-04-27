#ifndef LAB3_SRC_COLLEGE_H_
#define LAB3_SRC_COLLEGE_H


#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "college_structs.h"


namespace lab3 {




typedef lab3::college_structs::Instructor Instructor;
typedef lab3::college_structs::Student Student;
typedef lab3::college_structs::Course Course;
typedef lab3::college_structs::EnrollHistory EnrollHistory;




namespace college {




class College
{
	private:
		std::set<Student> student_roster;
		std::set<Instructor> instructor_roster;
		std::set<Course> course_history;
		EnrollHistory enroll_history{};
		
		const int printWidth {12};  // width padding for printf
	
	public:
		/*    Get Methods    */
		std::set<Student> get_studentRoster();
		std::set<Instructor> get_instructorRoster();
		std::set<Course> get_courseHistory();
		std::vector<std::pair<Student, std::string>> get_courseRoster(Course crs);
		std::vector<std::pair<Course, std::string>> get_studentHistory(Student stud);
		
		/*    Derived Get methods    */
		std::set<int> get_courseNumberSet(std::set<Course> courses);
		std::set<Course> get_instructorCourseSet(Instructor instr);
		
		/*    Collection Methods    */
		void collect_studentGrades(Student stud, std::vector<std::string> &grades);
		void collect_studentGrades(std::set<Student> students, std::vector<std::string> &grades);
		void collect_courseGrades(Course crs, std::vector<std::string> &grades);
		void collect_courseGrades(std::set<Course> courses, std::vector<std::string> &grades);
		void collect_courseGrades(std::set<Course> courses, std::vector<std::string> &grades, int crs_num);
		void collect_courseGrades(std::set<Course> courses, std::vector<std::string> &grades, int crs_num, std::string term);
		
		/*    Insertion Methods     */
		bool register_student(Student stud);
		bool register_instructor(Instructor instr);
		bool register_course(Course crs);
		
		/*    Conditional Tests    */
		bool pass(std::string grade);
		bool fail(std::string grade);
		bool withdraw(std::string grade);
		
		/*    Stats and Counting    */
		float passRate(std::vector<std::string> &grades);
		float withdrawRate(std::vector<std::string> &grades);
		
		/*    Reading    */
		void read(char *filename);
		void parseLine(std::string &data);  // helper to the read method
		
		/*    Writing    */
		static std::string timestamp();
		void print_studentSet(FILE *fp, std::set<Student> students);
		void print_instructorSet(FILE *fp, std::set<Instructor> instructors);
		void print_courseSet(FILE *fp, std::set<Course> courses);
		void print_courseRoster(FILE *fp, Course crs);
		void print_studentHistory(FILE *fp, Student stud);
};




} // end of college namespace




} // end of lab3 namespace


#endif  // LAB3_SRC_COLLEGE_H_
