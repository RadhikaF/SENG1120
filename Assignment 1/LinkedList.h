/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 2 - September - 2017
Course: SENG1120
Task: Assignment 1

This file contains is the header file for the LinkedList class. It contains the class definition and lists the member function prototypes
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include "node.h"

namespace radhika_assignment
{
	class LinkedList
	{
		public:
			typedef node::value_type value_type;	//create a type definition to make value_type synonymous with a string

			//Constructors
			LinkedList();
			LinkedList(const value_type& data);
			//Destructor
			~LinkedList();

			//Modification member functions
			
			//Precondition: Receives a value_type reference variable as a parameter
			//Postcondition: The supplied entry (value_type = string) is split into individual words
			//with each stored in a node and added to the tail of the linked list
			void add(value_type& data);
			
			//Precondition: None
			//Postcondition: The head node is removed and returned to the heap. 
			//If the list length was zero, the function returns without changing anything. 
			void remove_from_head();
			
			//Precondition: Receives a value_type reference variable (single word) as the argument
			//Postcondition: Removes any occurence of the supplied entry in the linked list
			void remove(const value_type&);
			
			//Precondition: the two inputs are an instances of LinkedList
			//Postcondition: the two lists are concatenated with the result stored in the 
			//left argument
			void operator += (const LinkedList&);
			
			//Postcondition: None
			//Postcondition: Returns the pointer to the head node
			node* get_head() const;
			
			//Postcondition: None
			//Postcondition: Returns the pointer to the tail node
			node* get_tail() const;
			
			//Precondition: None
			//Postcondition: A count of the number of nodes in the list is returned
			std::size_t length() const;
			
			//Precondition: Receives a value_type reference variable
			//Postcondition: Returns a count of how many times the supplied entry appears in the linked list
			int count(const value_type&);

		private:
			node* head;
			node* tail;
			node* current;
			int list_length;
	};
	
	//Precondition: Requires a linked list to retrieve data from.
	//Postcondition: Outputs the content of the linked list 
	std::ostream& operator << (std::ostream& out, const LinkedList&);
	
	//Precondition: Requires a linked list to store the data in
	//Postcondition: New node will have been added to the linked list containing the data inputted by the user
	std::istream& operator >> (std::istream& in, LinkedList&);
};

#endif