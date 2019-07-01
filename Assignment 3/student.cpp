/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 3 - November - 2017
Course: SENG1120
Task: Assignment 3

This file contains is the implementations file for the student class. It contains the implementations of the member functions listed in the header file.
*/

#include "student.h"
#include <string>

namespace lab09
{
	student::student(const int student_grade, const std::string student_name)
	{
		grade = student_grade;	//set the grade to the supplied entry
		name = student_name;	//set the name to the supplied entry
	}

	int student::get_grade() const
	{
		return grade;	//return the grade of the student
	}
	
	int& student::get_grade()
	{
		return grade;	//return the grade of the student
	}
	
	std::string student::get_name() const
	{
		return name;	//return the name of the student
	}
	
	std::string& student::get_name() 
	{
		return name;	//return the name of the student
	}
	
	void student::set_info(const std::string new_name, const int new_grade)
	{
		grade = new_grade;	//set the grade to the supplied entry
		name = new_name;	//set the name to the supplied entry
	}
	
	void student::set_grade(const int new_grade)
	{
		grade = new_grade;	//set the grade to the supplied entry
	}
	
	void student::set_name(const std::string new_name)
	{
		name = new_name;	//set the name to the supplied entry
	}
	
	std::ostream& operator << (std::ostream& out, const student& p)
	{
		return out << "(" << p.get_name() << "," << p.get_grade() << ")" << std::endl; //prints out the student info in the form of (name,grade)
	}
	
	bool operator < (const student& std1, const student& std2)
	{
		std::string a = std1.get_name();	//store the name of student 1 in a
		std::string b = std2.get_name();	//store the name of student 2 in b
		return (a < b);	//return true of a is less than b
	}
	
	bool operator > (const student& std1, const student& std2)
	{
		std::string a = std1.get_name();	//store the name of student 1 in a
		std::string b = std2.get_name();	//store the name of student 2 in b
		return (a > b);	//return true of a is greater than b
	}
}