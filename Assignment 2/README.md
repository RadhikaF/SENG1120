Using the LinkedList from Assignment 1, a Queue is implemented as a class template and create a sorting algorithm. 

The algorithm for sorting will work as follows:
1. Start with four queues. Three for the inputs, and one for the output. The three input
queues are populated with sequences of objects. The individual sequences are ordered
with objects going from smaller to largest values.
2. Compare the elements at the front of the input queues.
3. Remove the smallest one and place it in the output queue. Go back to 2 until all input
queues are empty.

To demonstrate the basic functionality, in the file sortingDemo:
a) Query the user for 3 sequences of inputs.
b) Check if the inputs are valid.
c) Run steps (2) and (3) and at the end display the contents of the output queue.
