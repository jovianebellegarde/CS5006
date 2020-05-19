// Compile this assignment with: gcc main.c -o main
//
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

	queue_t* test1 = create_queue(1);
	printf("Test 1: Attempting to add %d\n\n",1);
	queue_enqueue(test1,1);	
	printf("Removing: %d\n\n",queue_dequeue(test1));	

	free_queue(test1);
}


void unitTest2() {
	queue_t* test2 = create_queue(0);
	printf("Test 2: Attempting to add %d\n\n", 0);
	queue_enqueue(test2, 0);
	printf("Removing: %d\n\n", queue_dequeue(test2));

	free_queue(test2);


}
	
// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();
	unitTest2();
	return 0;
}
