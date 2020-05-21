// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You need to add sufficient testing.
void unitTest1(){

	stack_t* test1 = create_stack(8);
	if (create_stack(8) == NULL) {
		printf("The stack has a NULL value.\n\n");
	
	} else {
		printf("The stack does not have a NULL value.\n\n");

	}
	printf("Attempting to add %d\n\n", stack_enqueue(test1, 1));
	
	printf("Attempting to add %d\n\n", stack_enqueue(test1, 1));
	
	printf("Attempting to add %d\n\n", stack_enqueue(test1, 1));

	if (stack_enqueue(test1, 1) == -1) {
		printf("Can't enqueue on a NULL stack.\n\n");

	} else if (stack_enqueue(test1, 1) == 0) {
		printf("Can't enqueue on a full stack.\n\n");
	
	} else {
		printf("Continuing.\n\n");
	}

	printf("Removing %d:\n\n", stack_dequeue(test1));

	if (stack_dequeue(test1) == -1) {
		printf("The stack has a NULL value.\n\n");
	
	} else if (stack_dequeue(test1) == 0) {
		printf("The stack is empty and can't remove from it.\n\n");
	
	} else if (stack_dequeue(test1) == 1) {
		printf("Decreasing the stack size by 1.\n\n");
 	} else {
		printf("Checking to see if the stack is full.\n\n");

	}
	stack_full(test1);
	
	// Checking to see if queue is full
	if (stack_full(test1) == 1) {
		printf("The stack is full.\n\n");
	
	} else if (stack_full(test1) == -1) {
		printf("The stack is NULL.\n\n");
	
	} else {
		printf("The stack is not full.\n\n");}

	// Checking to see if stack is empty
	if (stack_empty(test1) == -1) {
		printf("The stack is NULL.\n\n");

	} else if (stack_empty(test1) == 0) {
		printf("The stack is not empty.\n\n");
	
	} else if (stack_empty(test1) == 1) {
		printf("The stack is empty.\n\n");

	}
	// Checking the size of the stack
	if (stack_size(test1) == -1) {
		printf("The stack is NULL.\n\n");
	
	} else {
		printf("The stack size is %d.\n\n", stack_size(test1)); 
	}		
	
}

void unitTest2() {
	stack_t* test2 = create_stack(0);
	if (create_stack(0) == NULL) {
		printf("The stack has a NULL value.\n\n");
	
	} else {
		printf("The stack does not have a NULL value.\n\n");

	}
	printf("Attempting to add %d\n\n", stack_enqueue(test2, 1));
	
	printf("Attempting to add %d\n\n", stack_enqueue(test2, 1));
	
	printf("Attempting to add %d\n\n", stack_enqueue(test2, 1));

	if (stack_enqueue(test2, 1) == -1) {
		printf("Can't enqueue on a NULL stack.\n\n");

	} else if (stack_enqueue(test2, 1) == 0) {
		printf("Can't enqueue on a full stack.\n\n");
	
	} else {
		printf("Continuing.\n\n");
	}
	printf("Removing %d:\n\n", stack_dequeue(test2));

	if (stack_dequeue(test2) == -1) {
		printf("The stack has a NULL value.\n\n");
	
	} else if (stack_dequeue(test2) == 0) {
		printf("The stack is empty and can't remove from it.\n\n");
	
	} else if (stack_dequeue(test2) == 1) {
		printf("Decreasing the stack size by 1.\n\n");
 	} else {
		printf("Checking to see if the stack is full.\n\n");

	}
	stack_full(test2);

	// Checking to see if queue is full
	if (stack_full(test2) == 1) {
		printf("The stack is full.\n\n");
	
	} else if (stack_full(test2) == -1) {
		printf("The stack is NULL.\n\n");
	
	} else {
		printf("The stack is not full.\n\n");
	}

	// Checking to see if stack is empty
	if (stack_empty(test2) == -1) {
		printf("The stack is NULL.\n\n");

	} else if (stack_empty(test2) == 0) {
		printf("The stack is not empty.\n\n");
	
	} else if (stack_empty(test2) == 1) {
		printf("The stack is empty.\n\n");

	}
	// Checking the size of stack
	if (stack_size(test2) == -1) {
		printf("The stack is NULL.\n\n");
	
	} else {
		printf("The stack size is %d.\n\n", stack_size(test2)); 
	}		
	
}		




// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();

	return 0;
}
