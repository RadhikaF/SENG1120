/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 2 - September - 2017
Course: SENG1120
Task: Assignment 1

This program stores the user's sentence in a linked list. The contents will be displayed, as well as the number of words and occurrences of the word SENG1120. 
A second sentence will be stored and concatenated with the first sentenc e, with the result stored in the first linked list. Both linked lists will be displayed. 
It will then display the length of the new first sentence, as well as how many times the word "is" occurs. Then it will ask the user to choose a word and remove 
all occurences of it from the second sentence and display both.
*/
#include <iostream>
#include <cstdlib>
#include "Queue.h"
using namespace std;
using namespace radhika_assignment2;

int main()
{
	int x = 4;
	Queue<int> *int_queue = new Queue<int>(x);
	int_queue->enqueue(x+2);
	int_queue->enqueue(x+2);
	cout<<int_queue->dequeue() << endl;

	Queue<std::string> *string_queue = new Queue<std::string>();
	std::string string = "Hello";
	string_queue->enqueue(string);
	string_queue->enqueue(string);
	cout<<string_queue->dequeue() << endl;

	int front_data = int_queue->front();
	
	cout<<front_data<<endl;
	
	size_t queue_size = int_queue->size();
	cout << "Int queue size > " << queue_size << endl;
	queue_size = string_queue->size();
	cout << "String queue size > " << queue_size << endl;
	
	return EXIT_SUCCESS;
	
}