/* Author: R.Feron		StNo:c3256870		Lab:Tuesday 12pm
Date: 2 - September - 2017
Course: SENG1120
Task: Assignment 1

This program stores the user's sentence in a linked list. The contents will be displayed, as well as the number of words and occurrences of the word SENG1120. 
A second sentence will be stored and concatenated with the first sentenc e, with the result stored in the first linked list. Both linked lists will be displayed. 
It will then display the length of the new first sentence, as well as how many times the word "is" occurs. Then it will ask the user to choose a word and remove 
all occurences of it from the second sentence and display both.
*/
#include "LinkedList.h"

using namespace std;
using namespace radhika_assignment;

int main()
{
	typedef node::value_type value_type;	//create a type definition to make value_type synonymous with a string

	LinkedList* inputOne = new LinkedList();	//create a pointer to a new linked list stored on the heap

	cout << "Please enter a sentence > " << endl;	//ask the user to input a sentence
	
	cin >> *inputOne;	//using the overloaded >> operator to store each word in a node within the linked list
	
	cout << "\nInput One > " << *inputOne;	//using the overloaded << operator, displays the contents of inputOne
	
	cout << "Number of words in Input One > " << inputOne->length() << endl; //displays the number of words in inputOne

	value_type word("SENG1120");	//creates a pointer to a new value_type variable initialised to contain "SENG1120"
	
	int occur = inputOne->count(word);		//call member function to store the number of times a specific word occurs in inputOne and storing it in an integer variable
	cout << "Number of times '" << word << "' occurs > " << occur << endl;		//display the number of times the word occured
	
	LinkedList* inputTwo = new LinkedList();	//create a pointer to a new linked list stored on the heap
	
	cout << "\nPlease enter a second sentence > " << endl;	//request the user to input a second sentence
	
	cin >> *inputTwo;	//store the user's input in inputTwo linked list
		
	*inputOne += *inputTwo;	//concatenate the two linked lists using the overloaded += operator
	
	cout << "\nAfter the concatenation of Input One and Input Two > " << endl;
	cout << "Input One > " << *inputOne;	//display inputOne
	cout << "Input Two > " << *inputTwo << endl;	//display inputTwo
	
	cout << "Length of Input One > " << inputOne->length() << endl;	//display the length of inputOne
	
	word = "is";	//set the variable word to contain the string "is"
	occur = inputOne->count(word);		//call member function to store the number of times a specific word occurs in inputOne and storing it in an integer variable
	cout << "Number of times '" << word << "' occurs > " << occur << endl;		//display the number of times the word occured
	
	cout << "\nPlease enter a word you wish to remove from Input Two > " << endl;		//ask the user to input a word they wish to remove from inputTwo
	cin >> word;	//store the user input in the value_type variable word
	
	inputTwo->remove(word);	//call the member function to remove occurrences of the word
	cout << "\nInput One > " << *inputOne;	//display inputOne
	cout << "Input Two > " << *inputTwo << endl;	//display inputTwo
	
	delete inputOne;	//remove inputOne from the stack
	delete inputTwo;	//remove inputTwo from the stack
	
}