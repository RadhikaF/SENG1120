/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 3 - November - 2017
Course: SENG1120
Task: Assignment 3

This file contains is the header file for the student class. It contains the class definition and lists the member function prototypes
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

namespace lab09
{
	class student
	{
	public:
		//Constructor
		student(int student_grade=-1, const std::string student_name = "");
		
		//Precondition: None
		//Postcondition: Returns the grade of the student
		int get_grade() const;
		
		//Precondition: None
		//Postcondition: Returns a reference variable of the grade of the student
		int& get_grade();
		
		//Precondition: None
		//Postcondition: Returns the name of the student
		std::string get_name() const;
		
		//Precondition: None
		//Postcondition: Returns a reference variable of the name of the student
		std::string& get_name();
		
		//Precondition: Receives an integer
		//Postcondition: Sets the grade of the student to the supplied entry
		void set_grade(const int new_grade);
		
		//Precondition: Receives a string
		//Postcondition: Sets the name of the student to the supplied entry
		void set_name(const std::string new_name);
		
		//Precondition: Receives a string and an integer
		//Postcondition: Sets the name and grade of the student to the supplied entries
		void set_info(const std::string new_name, const int new_grade);

	private:
		int grade;
		std::string name;
	};
	
	//Precondition: Requires a student variable to retrieve the data from
	//Postcondition: Outputs the information of the student in the form of (name, grade)
	std::ostream& operator << (std::ostream& out, const student& p);
	
	//Precondition: Requires a student variable to retrieve the data from
	//Postcondition: Returns a boolean indicating true if the name of student1 is less than the name of student2
	bool operator < (const student& std1, const student& std2);
	
	//Precondition: Requires a student variable to retrieve the data from
	//Postcondition: Returns a boolean indicating true if the name of student1 is greater than the name of student2
	bool operator > (const student& std1, const student& std2);
}

#endif