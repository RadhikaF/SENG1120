/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 3 - November - 2017
Course: SENG1120
Task: Assignment 3

This file contains is the header file for the node class. It contains the class definition and lists the member function prototypes
*/

#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <string>

namespace lab09
{
	template <typename item>
	
	class node
	{
		public:
		//Constructor
		node(const item& init_data = item(), node<item>* init_parent = NULL, node<item>* init_left = NULL, node<item>* init_right = NULL);
		//Destructor
		~node();
		
		//Modification member functions
		//Precondition: Receives a item reference variable
		//Postcondition: Sets the data of the node to the supplied entry
		void set_data(const item& new_data);
		
		//Precondition: Receives a pointer to a node type
		//Postcondition: Sets the left child pointer of the node to the supplied entry
		void set_left(node<item>* left_child);
		
		//Precondition: Receives a pointer to a node type
		//Postcondition: Sets the right child pointer of the node to the supplied entry
		void set_right(node<item>* right_child);
		
		//Precondition: Receives a pointer to a node type
		//Postcondition: Sets the parent pointer of the node to the supplied entry
		void set_parent(node<item>* parent_node);
		
		//Precondition: Receives a integer variable
		//Postcondition: Sets the grade member variable of the student item variable to the supplied entry
		void set_grade_data(const int new_grade);
		
		//Constant member functions that query data but don't change it
		//Precondition: None
		//Postcondition: Returns the name of the student
		std::string data_name() const;
		
		//Precondition: None
		//Postcondition: Returns a reference variable to the name of the student
		std::string& data_name();
		
		//Precondition: None
		//Postcondition: Returns the grade of the student
		int data_grade() const;
		
		//Precondition: None
		//Postcondition: Returns a reference variable of the grade of the student
		int&  data_grade();
		
		//Precondition: None
		//Postcondition: Returns the data of the student
		item get_data() const;
		
		//Precondition: None
		//Postcondition: Returns a reference variable of the data of the student
		item& get_data();
		
		//Precondition: None
		//Postcondition: Returns the constant left child pointer
		const node<item>* get_left() const;
		
		//Precondition: None
		//Postcondition: Returns the left child pointer
		node<item>* get_left();
		
		//Precondition: None
		//Postcondition: Returns the constant right child pointer
		const node<item>* get_right() const;
		
		//Precondition: None
		//Postcondition: Returns the right child pointer
		node<item>* get_right();
		
		//Precondition: None
		//Postcondition: Returns the constant parent pointer
		const node<item>* get_parent() const;
		
		//Precondition: None
		//Postcondition: Returns the parent pointer
		node<item>* get_parent();
		
		//Precondition: None
		//Postcondition: Returns a boolean indicating true if the node is a leaf node
		bool is_leaf() const;
		
		//Precondition: None
		//Postcondition: Returns a boolean indicating true if the node has only one child
		bool has_one_child() const;
		
		//Precondition: None
		//Postcondition: Returns a boolean indicating true if the node is a right child
		bool is_right_child() const;
		
		private:
		item data;
		node<item>* left;
		node<item>* right;
		node<item>* parent;
	
	};
}
#include "node.template"
#endif