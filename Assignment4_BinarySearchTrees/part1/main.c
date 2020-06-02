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
	bst_t* empty = create_bst();
	if (bst_empty(empty) == 1) {
		printf("This tree is empty\n\n");

	} else {
		printf("Test failed\n\n");
	}
	free_bst(empty);
}


int main(){
	unitTest1();   
    	return 0;
}







