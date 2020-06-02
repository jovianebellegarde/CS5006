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
		bst_print(empty, 1);
		printf("This tree is empty\n\n");

	} else {
		printf("Test failed\n\n");
	}
	
}

unitTest2() {
	bst_t* partial = create_bst();
	bst_add(partial, 1);
        bst_add(partial, 2);
	bst_add(partial, 6);
	bst_add(partial, 4);
	bst_add(partial, 3);
	bst_add(partial, 5);
	if (bst_empty(partial) == 0) {
                printf("Tree not empty\n\n");

        } else {
                printf("Test failed\n\n");
        }

	bst_print(partial, 3);
	printf("The sum is:%d\n\n", bst_sum(partial));
	printf("Finding the number %d\n\n", 4, find(partial, 4));

        free_bst(partial);


}



int main(){
	unitTest1();   
	unitTest2();
    	return 0;
}







