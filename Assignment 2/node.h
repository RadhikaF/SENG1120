/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 2 - September - 2017
Course: SENG1120
Task: Assignment 1

This file contains is the header file for the node class. It contains the class definition and lists the member function prototypes
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

namespace radhika_assignment2
{
	template <typename object>
	class node
	{
		public:
		
		//Constructor
		node(const object& initial_data = object(), node<object>* initial_next = NULL, node<object>* initial_previous = NULL);
		
		//Modification member functions
		
		//Precondition: Receives a value_type reference variable
		//Postcondition: Sets the data of the node to the supplied entry
		void set_data(const object&);
		
		//Precondition: Receives a pointer to a node type
		//Postcondition: Sets the next pointer of the node to the supplied entry
		void set_next(node<object>*);
		
		//Precondition: Receives a pointer to a node type
		//Postcondition: Sets the previous pointer of the node to the supplied entry
		void set_previous(node<object>*);
		
		//Constant member functions query data but don't change it
		
		//Precondition:	None
		//Postcondition: Returns the current data
		object get_data() const;
		//Precondition: None
		//Postcondition: Returns the next pointer
		node<object>* next_pointer() const;
		//Precondition: None
		//Postcondition: Returns the previous pointer
		node<object>* previous_pointer() const;

		private:
			object data;
			//node pointers going to next and previous nodes
			node<object>* next;
			node<object>* previous;
	};
};
#include "node.cpp"

#endif