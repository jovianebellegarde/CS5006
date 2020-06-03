// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free
// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// ====================================================
// ================== Program Entry ===================
// ====================================================

unitTest1() {

	printf("Running TEST 1\n\n");
	bst_t* empty = create_bst();
	if (bst_empty(empty) == 1) {
		bst_print(empty, 1);
		printf("This tree is empty\n\n");

	} else {
		printf("Test failed\n\n");
	}
	
}
/*
unitTest2() {
	printf("Running TEST 2\n\n");
	bst_t* partial = create_bst();
	bst_add(partial, 50);
        bst_add(partial, 20);
	bst_add(partial, 60);
	if (bst_add(partial, 70) == 0) {
		printf("Couldn't add\n\n");
	}
	if (bst_empty(partial) == 0) {
                printf("Tree is not empty\n\n");

        } else {
                printf("Test failed\n\n");
        }

        bst_print(partial, 10);
	printf("\n\n");
	printf("The sum is: %d\n\n", sum(partial));
	//printf("Finding the number %d\n\n", find(partial, 4));

        free_bst(partial);

}

*/

unitTest2() {

	printf("TEST 2\n\n");
	bst_t* partial = create_bst();
	bst_add(partial, 20);
	
	if (bst_add(partial, 20) == 0) {

		printf("Test has failed\n\n");
	} else if (bst_add(partial, 20) == 1) {
		printf("Means the node was empty\n\n");
	} else {
		printf("This printed meaning that returned NULL\n\n");
	}
	free_bst(partial);

}

int main(){
	unitTest1();   
	unitTest2();
    	return 0;
}







