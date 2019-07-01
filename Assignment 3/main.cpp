/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 3 - November - 2017
Course: SENG1120
Task: Assignment 3

This program implements a Binary Search Tree to store the name of students and their grades. It prints out all the names and grades 
using the inorder traversal, the number of students with grades<50 and the average grade. It will then delete all the students who 
had a grade < 50 and repeat the steps. It will then request the user to input a name to search for in the tree. If it is found, the 
name and grade will be printed out, and if it is not found it will inform the user
*/

#include <iostream>
# include <cstdlib>
#include "BST.h"
#include "student.h"
#include <string>
#include <fstream>
using namespace std;
using namespace lab09;

int main()
{
	int grade, fail_grade = 50, total;
	double average;
	string name;
	std::size_t found;
	ifstream inFile;
	
	inFile.open("datafile.txt");	//open the file
	student* new_student = new student();	//create a pointer to a new student stored on the heap
	BST<student>* BST_ = new BST<student>();	//create a pointer to a new BST stored on the heap with variable student

	if(!inFile)	//if the file cannot be opened
	{
		cerr << "Unable to open datafile.txt";	//warn the user
		exit(1);	//and exit the program
	}
	
	while (!inFile.eof())	//while the end of file has not been reached
	{
		inFile >> name;	//input the first word into the string name
		inFile >> grade;	//input the second word into the integer grade
		new_student->set_info(name,grade);	//set the new_student to contain the name and grade
		BST_->insert(*new_student);	//add the data to the BST
	}
	inFile.close();	//close the file
	//print all names and grades using inorder traversal
	cout << *BST_;
	//print out how many students had grade < 50
	found = BST_->occurences(50);
	cout << "\nFF: " << found << endl;
	//print out average grade of class
	total = BST_->grade_sum();
	cout << "Sum > "<< total << endl;
	average = 1.0*total/BST_->size();
	cout << "Average: " << average << endl;
	
	//delete students with grade < 50
	BST_->remove(fail_grade);
	//print out all names and grades
	cout << "\nAfter removing all students with grade < 50" <<endl;
	cout<<*BST_<<endl;
	//print out how many students had grade < 50
	found = BST_->occurences(50);
	cout << "FF: " << found << endl;
	//print out average grade of class
	total = BST_->grade_sum();
	cout << "Sum > "<< total << endl;
	average = 1.0*total/BST_->size();
	cout << "Average: " << average << endl;
	
	//input name from user and search for it in the tree
	string target;
	cout << "\nPlease enter a name to search > " << endl;
	cin >> target;
	BST_->search(target);
	
	delete BST_;
	
	return EXIT_SUCCESS;
}

