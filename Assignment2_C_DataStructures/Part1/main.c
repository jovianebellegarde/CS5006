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
	printf("Test 1: Attempting to add %d\n",1);
	queue_enqueue(test1, 1);	
	printf("Removing: %d\n\n",queue_dequeue(test1));	

	free_queue(test1);
}

void unitTest2() {
	queue_t* test2 = create_queue(40);
	printf("Test 2: Attempting to add %d\n", 40);
	queue_enqueue(test2, 40);
	printf("removing: %d\n\n", queue_dequeue(test2));

	free_queue(test2);
}


void unitTest3() {
        queue_t* test3 = create_queue(4);
        printf("Test 3: Attempting to add %d\n", 4);
        queue_enqueue(test3, 4);
        printf("removing: %d\n\n", queue_dequeue(test3));

        free_queue(test3);
}

void unitTest4() {
        queue_t* test4 = create_queue(0);
        printf("Test 4: Attempting to add %d\n", 0);
        queue_enqueue(test4, 4);
        printf("removing: %d\n\n", queue_dequeue(test4));

        free_queue(test4);
}

void unitTest5() {
	queue_t* test5 = create_queue(50);
//	queue_t* test5b = create_queue(100);
	printf("Test 5: Attempting to add %d\n", 50);
	queue_enqueue(test5, 50);
	printf("removing: %d\n\n", queue_dequeue(test5));

	free_queue(test5);
	//free_queue(test5b);
}

void unitTest6() {
	queue_t* test6 = create_queue(10);
	printf("Test 6: Attempting to add %d\n", 10);
	queue_enqueue(test6, 10);
	printf("removing: %d\n\n", queue_dequeue(test6));
	queue_enqueue(test6, 10);
	printf("Attempting to add %d again\n", 10);
	printf("removing: %d\n\n", queue_dequeue(test6));

	free_queue(test6);

}

void unitTest7() {
	queue_t* test7 = create_queue(0);
	queue_t* test7b = create_queue(70);
	printf("Test 7: Attempting to add %d\n", 0);
	queue_enqueue(test7b, 100);
	printf("removing: %d\n\n", queue_dequeue(test7b));

	free(test7);
	free(test7b);
}

void unitTest8() {
	queue_t* test8 = create_queue(3);
	printf("Test 8: Attempting to add %d\n", 3);
	queue_enqueue(test8, 3);
	printf("removing: %d\n\n", queue_dequeue(test8));

	free(test8);
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
	unitTest6();
	unitTest7();
	unitTest8();
	return 0;
}
