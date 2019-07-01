/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 3 - November - 2017
Course: SENG1120
Task: Assignment 3

This file contains is the header file for the BST class. It contains the class definition and lists the member function prototypes
*/

#ifndef BST_H
#define BST_H
#include <cstdlib>
#include <iostream>
#include "node.h"

namespace lab09
{
	template <typename item>
	
	class BST
	{
		public:
		//Consturctors
		BST();
		BST(const item& data);
		
		//Destructor
		~BST();
		
		//Precondition: None
		//Postcondition: Returns the number of nodes in the binary search tree
		std::size_t size() const;
		
		//Precondition: Receives an item reference variable
		//Postcondition: If the tree is empty, a new root node will be created containing the supplied data. Else a recursive function 
		//is called to add the new node with the data in the appropriate position
		void insert(item& data);
		
		//Precondition: None
		//Postcondition: Returns the data contained by the root
		item root_data() const;
		
		//Precondition: Receives two item reference variables
		//Postcondition: Returns -1 if the name of item a is less than that of b, returns 0 if they are equal and returns 1 is a is greater
		int compare(const item& a, const item& b);
		
		//Precondition: Receives a pointer to a node and an output stream
		//Postcondition: Recursively performs inorder traversal and outputs the data of each node to the output stream
		void inOrder(node<item>* node, std::ostream& output) const;
		
		//Precondition: Receives a pointer to a node and an item reference variable
		//Postcondition: Recursive function that adds a new node with the supplied data in the appropriate position in the tree
		void add(node<item>* current_node, item& data);	
		
		//Precondition: Receives a string
		//Postcondition: Intermediate function that calls a recursive function to search for the target string
		bool search(const std::string& target) const;
		
		//Precondition: Receives a pointer to the current node and a string
		//Postcondition: Recursive function that returns a boolean indicating true if the target string has been found and outputs the data at that node
		bool find(node<item>* BTNode, const std::string& target) const;
		
		//Precondition: Receives an integer
		//Postcondition: If the tree is not empty, it will call a recursive function to search for the number of occurrences of the target integer
		std::size_t occurences(const int& target);
		
		//Precondition: Receives a pointer to the current node and the integer target
		//Postcondition: Recursive function that returns the number of occurrences of the target in the tree
		std::size_t target_count(const node<item>* current_node, const int& target);
		
		//Precondition: None
		//Postcondition: If the tree is not empty, it will call a recursive function to find the sum of all the student grades in the tree
		int grade_sum();
		
		//Precondition: Receives a node pointer to the current node
		//Postcondition: Recursive function that returns the sum of all the grades of the students in the tree
		int sum(const node<item>* current_node);
		
		//Precondition: None
		//Postcondition: Returns a pointer to the root node
		node<item>* get_root() const;
		
		//Precondition: Receives a pointer to the current node
		//Postcondition: Returns the left-most node of the current node
		node<item>* find_min(node<item>* current_node);
		
		//Precondition: Receives a integer
		//Postcondition: Returns false of the tree is empty and calls a recursive function to remove the target otherwise		
		bool remove(int& data);
		
		//Precondition: Receives a pointer to the current node and an integer
		//Postcondition: Returns true if all the nodes with grades less than the supplied entry have been removed
		bool remove_(node<item>* current_node, int& data);
		
		private:
		node<item>* root;
		std::size_t nodes;
	};
	//Precondition: Requires a BST variable to retrieve the data from
	//Postcondition: Outputs the contents of the tree through inorder traversal
	template<typename item>
	std::ostream& operator << (std::ostream& output, const BST<item>& p);

}
#include "BST.template"
#endif