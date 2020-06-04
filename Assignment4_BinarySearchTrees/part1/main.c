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

void unitTest1() {
	printf("Test 1 - Emtpy Create and add\n\n");

	bst_t* empty = create_bst();

	bst_add(empty, 15);
	bst_add(empty, 10);
	bst_add(empty, 20);
	bst_add(empty, -3);
	bst_add(empty, 100);

	bst_print(empty, 0);
	
	free_bst(empty);

}


void unitTest2() {
	printf("Test 2 - NULL create and add\n\n");

	bst_t* testNull = NULL;

	bst_add(testNull, 7);
	bst_add(testNull, 1);
	bst_add(testNull, 5);
	bst_add(testNull, 10);
	
	bst_print(testNull, 0);

	free_bst(NULL);

}


void unitTest3() {
	printf("Test 3 - empty create and print\n\n");

	bst_t* empty = create_bst();
	bst_print(empty, 0);
	
	if (bst_empty(empty) == -1) {

		printf("There is a NULL\n\n");
	
	} else if (bst_empty(empty) == 1) {

		printf("The tree is empty\n\n");
	
	} else if (bst_empty(empty) == 0) {

		printf("The tree is not empty\n\n");
	}

	

	if (bst_size(empty) == -1) {

		printf("The tree is NULL\n\n");
	} else {
		printf("The size is %d\n\n", bst_size(empty));
	}
	

	free_bst(empty);

}


void unitTest4() {
        printf("Test 4 - partial\n\n");

        bst_t* partial = create_bst();


        if (bst_empty(partial) == -1) {

                printf("There is a NULL\n\n");

        } else if (bst_empty(partial) == 1) {

                printf("The tree is empty\n\n");

        } else if (bst_empty(partial) == 0) {

                printf("The tree is not empty\n\n");
        }

	bst_add(partial, 5);
	bst_add(partial, 1);
	bst_add(partial, 8);

        if (bst_size(partial) == -1) {

                printf("The tree is NULL\n\n");
        
	} else {
                printf("The size is %d\n\n", bst_size(partial));
        }

	   
        
	if (find(partial, 1) == 1) {
                printf("Found the number 1\n\n");
        
	} else {
		printf("Didn't find 1\n\n");

	}

        if (find(partial, 5) == 1) {
                printf("Found the number 5\n\n");
        
	} else {
		printf("Didn't find 5\n\n");
	}

        if (find(partial, 8) == 1) {
                printf("Found the number 8\n\n");
        
	} else {
                printf("Didn't find 8\n\n");
	}
        
	if (find(partial, 0) == 1) {
                printf("Found the number 0\n\n");
        
	} else {
		printf("Didn't find 0\n\n");
	}

	if (sum(partial) == -1) {

		printf("Sum: NULL\n\n");
	
	} else {
		printf("The sum is %d\n\n", sum(partial));
	}

	if (bst_size(partial) == -1) {
		printf("The size is NULL\n\n");

	} else {
		printf("The size is %d\n\n", bst_size(partial));
	}

	bst_print(partial, 0);


        free_bst(partial);
}



void unitTest5() {
        printf("Test 5 - NULL create and print\n\n");

        bst_t* testNull = NULL;
 

        if (bst_empty(testNull) == -1) {

                printf("There is a NULL\n\n");

        } else if (bst_empty(testNull) == 1) {

                printf("The tree is empty\n\n");

        } else if (bst_empty(testNull) == 0) {

                printf("The tree is not empty\n\n");
        }

	bst_add(testNull, 5);
	bst_add(testNull, 1);
	bst_add(testNull, 8);

        if (bst_size(testNull) == -1) {

                printf("The tree is NULL\n\n");
        
	} else {
                printf("The size is %d\n\n", bst_size(testNull));
        }

	   
        
	if (find(testNull, 1) == 1) {
                printf("Found the number 1\n\n");
        
	} else {
		printf("Didn't find 1\n\n");

	}

        if (find(testNull, 5) == 1) {
                printf("Found the number 5\n\n");
        
	} else {
		printf("Didn't find 5\n\n");
	}

        if (find(testNull, 8) == 1) {
                printf("Found the number 8\n\n");
        
	} else {
                printf("Didn't find 8\n\n");
	}
        
	if (find(testNull, 0) == 1) {
                printf("Found the number 0\n\n");
        
	} else {
		printf("Didn't find 0\n\n");
	}

	if (sum(testNull) == -1) {

		printf("Sum: NULL\n\n");
	
	} else {
		printf("The sum is %d\n\n", sum(testNull));
	}

	if (bst_size(testNull) == -1) {
		printf("The size is NULL\n\n");

	} else {
		printf("The size is %d\n\n", bst_size(testNull));
	}
 
	bst_print(testNull, 0);


        free_bst(testNull);
}


int main(){

	unitTest1();   
	unitTest2();
	unitTest3();
	unitTest4();
	unitTest5();

	return 0; 
}







