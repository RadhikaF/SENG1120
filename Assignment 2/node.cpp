/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 2 - September - 2017
Course: SENG1120
Task: Assignment 1

This file contains is the implementations file for the node class. It contains the implementations of the member functions listed in the header file.
*/

#include <iostream>

namespace radhika_assignment
{
	template <typename object>

	node<object>::node(const object& initial_data, node<object>* initial_next, node<object>* initial_previous)
	{
		data = initial_data;		//set the data of the node to the initial_data (value_type() if not provided)
		next = initial_next;		//set the next pointer to the initial next pointer provided (NULL if not provided)
		previous = initial_previous;	//set the previous pointer to the initial previous pointer provided (NULL if not provided)
	}
	
	template <typename object>
	void node<object>::set_data(const object& new_data)
	{
		data = new_data;		//set the node data to the supplied entry of new_data
	}

	template <typename object>
	void node<object>::set_next(node<object>* next_link)
	{
		next = next_link;	//set the next pointer to the supplied node pointer of next_link
	}
	
	template <typename object>
	void node<object>::set_previous(node<object>* previous_link)
	{
		previous = previous_link;	//set the previous pointer to the supplied node pointer of previous_link
	}
	
	template <typename object>
	object node<object>::get_data() const
	{
		return data;		//return the data contained by the node
	}

	template <typename object>
	node<object>* node<object>::next_pointer() const
	{
		return next;		//return the next pointer
	}
	
	template <typename object>
	node<object>* node<object>::previous_pointer() const
	{
		return previous;		//return the previous pointer
	}
}