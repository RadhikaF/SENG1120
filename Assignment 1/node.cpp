/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 2 - September - 2017
Course: SENG1120
Task: Assignment 1

This file contains is the implementations file for the node class. It contains the implementations of the member functions listed in the header file.
*/

#include <iostream>
#include "node.h"

namespace radhika_assignment
{
	typedef std::string value_type;	//create a type definition to make value_type synonymous with a string

	node::node(const value_type& initial_data, node* initial_next, node* initial_previous)
	{
		data = initial_data;		//set the data of the node to the initial_data (value_type() if not provided)
		next = initial_next;		//set the next pointer to the initial next pointer provided (NULL if not provided)
		previous = initial_previous;	//set the previous pointer to the initial previous pointer provided (NULL if not provided)
	}
	
	void node::set_data(const value_type& new_data)
	{
		data = new_data;		//set the node data to the supplied entry of new_data
	}

	void node::set_next(node* next_link)
	{
		next = next_link;	//set the next pointer to the supplied node pointer of next_link
	}
	
	void node::set_previous(node* previous_link)
	{
		previous = previous_link;	//set the previous pointer to the supplied node pointer of previous_link
	}
	
	value_type node::get_data() const
	{
		return data;		//return the data contained by the node
	}

	node* node::next_pointer() const
	{
		return next;		//return the next pointer
	}
	
	node* node::previous_pointer() const
	{
		return previous;		//return the previous pointer
	}
}