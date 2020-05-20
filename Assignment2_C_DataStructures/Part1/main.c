// Compile this assignment with: gcc main.c -o main
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You need to add sufficient testing.
void unitTest1(){
	
	// Should print out a size of 6, adding 7 removing 1
	queue_t* test1 = create_queue(7);
	printf("Attempting to add %d\n\n", 1);
	queue_enqueue(test1, 1);

	printf("Attempting to add %d\n\n", 1);
	queue_enqueue(test1, 1);

	printf("Removing: %d\n\n", queue_dequeue(test1));
	
	printf("Attempting to add %d\n\n", 1);
        queue_enqueue(test1, 1);

        printf("Attempting to add %d\n\n", 1);
        queue_enqueue(test1, 1);

        printf("Attempting to add %d\n\n", 1);
        queue_enqueue(test1, 1);

        printf("Attempting to add %d\n\n", 1);
        queue_enqueue(test1, 1);
        
	printf("Attempting to add %d\n\n", 1);
        queue_enqueue(test1, 1);
	
	printf("The queue size is %d\n\n", queue_size(test1));
	if (queue_full(test1)) {
		printf("The stack is full\n");

	} else {
		printf("The stack is not full.\n");
	free(test1);
	}
}

void unitTest2() {
	
	queue_t* test2 = create_queue(0);
	printf("Attempting to add %d\n\n", 1);
	queue_enqueue(test2, 1);
	
	if (queue_dequeue(test2) == 0) {
		printf("The queue size is 0.\n\n");
	
	} else if (queue_dequeue(test2) == -1) {
		printf("The queue is assigned to NULL.\n\n");
	
	} else {
		printf("Removing: %d\n\n", queue_dequeue(test2));

	}
	printf("The queue size is %d\n\n", queue_size(test2));
	
	free(test2);

}

void unitTest3() {
	
	// Creating a NULL queue
	queue_t* test3 = NULL;
	printf("Check if queue is NULL, should give me a %d\n", 
	queue_full(test3));
	free_queue(test3);
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();
	unitTest2();
	unitTest3();

	return 0;
}
