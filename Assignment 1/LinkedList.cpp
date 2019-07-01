/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 2 - September - 2017
Course: SENG1120
Task: Assignment 1

This file contains is the implementations file for the LinkedList class. It contains the implementations of the member functions listed in the header file.
*/
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"

namespace radhika_assignment
{
	typedef node::value_type value_type;	//create a type definition to make value_type synonymous with a string

	//Create an empty linked list
	LinkedList::LinkedList()
	{
		head = NULL;	//set head pointer to NULL
		tail = NULL;	//set tail pointer to NULL
		current = NULL;	//set current pointer to NULL
		list_length = 0;	//set list length to zero
	}
	
	//Create a linked list with data
	LinkedList::LinkedList(const value_type& data)
	{
		head = new node(data);	//create a new node and let the head pointer point to it
		tail = head;	//set the tail to point to the head
		current = tail;	//set the current pointer to point to the tail
		list_length = 1;	//set list length to 1
	}
	
	//Destructor: Ensures all nodes are removed from the heap when a linked list is deleted
	LinkedList::~LinkedList()
	{
		while(head != NULL)	//while the head does not point to NULL
			remove_from_head();	//call the function to remove the head node from the linked list
		tail = NULL;	//set tail to NULL
	}
	
	void LinkedList::add(value_type& data)
	{
		value_type add_data;	//create a value_type variable called add_data
		int size = data.length();	//store the length of the data string in the integer size
		data.insert(size, " ");	//insert a space at the end of the string (otherwise the last word will not be removed since no spaces will have been found)
		
		while (data.length() > 0)	//while the string is not empty
		{
			std::size_t pos = data.find(" "); //find index of first space
			add_data = data.substr(0, pos);	//make substring at that index
			
			//add substring for empty lists
			if (list_length == 0)
			{
				head = new node(add_data);	//create a new node and set the head to pointer to it
				tail = head;	//set tail to point to head
				current = tail;	//set current to point to tail
				list_length = 1;	//let list length equal 1
			}
			//insert node with substring to the tail
			else
			{
				node* newNode = new node(add_data);	//create a new node on the heap
				tail->set_next(newNode);	//set tail's next pointer to the new tail
				newNode->set_previous(tail);	//set the new node's previous pointer to the node at the current tail
				tail = newNode;	//set the tail pointer from the list to the new node
				list_length++;	//increment the list length
				newNode=NULL;	//set the temporary new node pointer to NULL
			}
			data = data.substr(pos+1);	//adjust word so it no longer contains first substring
		}
	}
	
	void LinkedList::remove_from_head()
	{
		//Do nothing for an empty list
		if (list_length == 0)
		{
			return;
		}
		//remove the final node if only one node is in the list
		else if (list_length == 1)
		{
			delete head;	//delete the head node
			head = NULL;	//set the head pointer to NULL
			tail = NULL;	//set the tail pointer to NULL
			list_length--;	//Decrement the list length
			return;
		}
		else
		{
			node* temp_head = head;	//create a temp_head and set it as the current head pointer
			head = temp_head->next_pointer();	//rearrange the head pointer for the list
			delete temp_head;	//delete the old head node
			list_length--;	//Decrement list length
			temp_head = NULL;	//set temp_head to NULL
		}
	}
	
	std::size_t LinkedList::length() const
	{
		return list_length;	//returns the length of the linked list
	}
		
	/*takes single string, returns count of how 
	many times word appears in linkedlist*/
	int LinkedList::count(const value_type& target)
	{
		int count = 0;	//initialise integer count to zero
		
		for(current = head; current!=NULL; current = current->next_pointer())	//traverse the list until the end
		{
			if (target == current->get_data())	//if the current node contains the target data
			{
				count++;	//increment count
			}
		}
		return count;	//returns count of how many times the target word appears in the list		
	}
	
	node* LinkedList::get_head() const
	{
		return head;	//returns the head pointer of the list
	}
	
	node* LinkedList::get_tail() const
	{
		return tail;	//returns the tail pointer of the list
	}
	
	/*Overloaded concatenation operator (i.e. ‘+=’). The result of use of 
	this operator is the LinkedList arguments are concatenated and the 
	answer is stored in the left argument.*/
	void LinkedList::operator += (const LinkedList& list2)
	{
		//If list two is empty do nothing
		if (list2.length() == 0)
		{
			return;
		}
		//Else copy data from list 2 and add to list 1
		else
		{
			node* temp_ptr = list2.get_head();	//create a temp_ptr and set it to the head of list2
			
			while (temp_ptr != NULL)	//while the temp_ptr hasn't reached the end of the list
			{
				value_type add_data = temp_ptr->get_data();	//create value_type variable and set it to the data found in the node current pointed to by temp_ptr
				add(add_data);	//call the function to add the list2 data to the tail of list 1
				temp_ptr = temp_ptr->next_pointer();	//set temp_ptr to the next node
			}			
		}
	}
	
	std::ostream& operator << (std::ostream& out, const LinkedList& list)
	{
		if (list.length() == 0)	//if the list is empty
		{
			out << "Empty list" << std::endl;	//return a message saying the list is empty
		}
		else
		{
			node* temp_ptr;		//create a temp_ptr	
			for (temp_ptr = list.get_head(); temp_ptr != NULL; temp_ptr = temp_ptr->next_pointer())	//traverse the list using temp_ptr
			{
				out << temp_ptr->get_data() << " ";	//output the data found at the node pointed to by temp_ptr
			}
			out << std::endl;	//end line
		}

		return out;
	};
	
	std::istream& operator >> (std::istream& in, LinkedList& list)
	{
		value_type data;	//create a value_type variable
		std::getline(in,data);	//receive the entire line inputted by the user and store in the value_type variable data
		
		list.add(data);	//call the function for list2 to add the received data to the tail of the list
		
		return in;
	}
	
	
	/*remove() which takes a single word (represented as a string) argument
	and removes any occurrence of that word in the LinkedList*/
	void LinkedList::remove(const value_type& target)
	{
		if (list_length == 0)	//if the list is empty do nothing
		{
			return;
		}
		else
		{
			current = head;	//set the current pointer to the head pointer
			while(current!= NULL)	//while current doesn't point to NULL (ie. has not finished traversing the list)
			{
				if(target == current->get_data())	//if the data contained by the node pointed to by current is the same are the target data
				{	//remove the current node
					if (list_length == 1)	//if the list length is 1
					{
						delete head;	//delete the head node
						head = NULL;	//set head pointer to NULL
						tail = NULL;	//set tail pointer to NULL
						list_length--;	//decrement list length
						return;
					}
					else if (current == head)	//if the target is the head node
					{
						node* temp_head = head;		//create a temp _head and set it as the current head pointer
						head = temp_head->next_pointer();	//rearrange the head pointer for the list so it pointers to the next node
						head->set_previous(NULL);	//create a link to the previous node from the new head node
						delete temp_head;	//delete the old head node
						list_length--;		//decrement the list length
						temp_head = NULL;	//set temp_head to NULL
						current = head;		//make the current pointer point to the head pointer
					}
					else if (current == tail)	//if the target is the tail node
					{
						node* temp_tail = tail;		//create a temp_tail and set it as the current tail pointer
						tail = temp_tail->previous_pointer();	//rearrange the tail pointer to point to the previous node
						tail->set_next(NULL);		//set the pointer pointing to the next node to NULL
						delete temp_tail;		//delete the old tail node
						list_length--;		//decrement list length
						temp_tail = NULL;	//set temp_tail to NULL
						current = tail;		//make the current pointer point to the tail pointer
					}
					else	//else if the target is an internal node
					{
						node* temp_ptr = current->previous_pointer();	//create a temp_ptr and set it to the node previous to the current node
						temp_ptr->set_next(current->next_pointer());	//create a forward link between the previous and next node of the current node
						temp_ptr = current->next_pointer();			//set temp_ptr to point to the node after the current node
						temp_ptr->set_previous(current->previous_pointer());		//create a backward link between the previous and next node of the current node
						delete current;		//delete the current node
						current = temp_ptr;		//set the current pointer to point to the temp_ptr node
						temp_ptr = NULL;		//set temp_ptr to NULL
						list_length--;	//decrement list length
					}
				}
				else	//else if the target is not the current node
				{
					current = current->next_pointer();	//set current to point to the next node
				}
			}
		}
	}
}