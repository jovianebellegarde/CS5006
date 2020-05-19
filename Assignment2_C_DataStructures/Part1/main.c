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


void unitTest3() {
	queue_t* test3 = create_queue(5);
        printf("Test 3: Attempting to add %d\n\n", 5);
        queue_enqueue(test3, 5);
        printf("Removing: %d\n\n", queue_dequeue(test3));

	free_queue(test3);	

	queue_t* test3b = create_queue(5);
        printf("Test 3: Attempting to add %d again \n\n", 5);
        queue_enqueue(test3b, 5);
        printf("Removing: %d again\n\n", queue_dequeue(test3b));

        free_queue(test3b);

}	

void unitTest4() {
	queue_t* test4 = create_queue(0);
        printf("Test 4: Attempting to add %d\n\n", 5);
	
        queue_enqueue(0, 0);
        printf("Removing: %d\n\n", queue_dequeue(test4));

	free_queue(0);
}

void unitTest5() {
	queue_t* test5 = create_queue(7);
	
	int checking_empty = queue_empty(test5);
	
	if (checking_empty == 1) {
		printf("The queue is empty.\n");

	} else {
		printf("The queue is not empty.\n");

	queue_dequeue(test5);
	free(test5);
	}
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();
	unitTest5();
	return 0;
