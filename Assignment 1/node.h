/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 2 - September - 2017
Course: SENG1120
Task: Assignment 1

This file contains is the header file for the node class. It contains the class definition and lists the member function prototypes
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

namespace radhika_assignment
{
	class node
	{
		public:
		typedef std::string value_type;	//create a type definition to make value_type synonymous with a string
		
		//Constructor
		node(const value_type& initial_data = value_type(), node* initial_next = NULL, node* initial_previous = NULL);
		
		//Modification member functions
		
		//Precondition: Receives a value_type reference variable
		//Postcondition: Sets the data of the node to the supplied entry
		void set_data(const value_type&);
		
		//Precondition: Receives a pointer to a node type
		//Postcondition: Sets the next pointer of the node to the supplied entry
		void set_next(node*);
		
		//Precondition: Receives a pointer to a node type
		//Postcondition: Sets the previous pointer of the node to the supplied entry
		void set_previous(node*);
		
		//Constant member functions query data but don't change it
		
		//Precondition:	None
		//Postcondition: Returns the current data
		value_type get_data() const;
		//Precondition: None
		//Postcondition: Returns the next pointer
		node* next_pointer() const;
		//Precondition: None
		//Postcondition: Returns the previous pointer
		node* previous_pointer() const;

		private:
			value_type data;
			//node pointers going to next and previous nodes
			node* next;
			node* previous;
	};
};

#endif