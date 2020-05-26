// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.



// ====================================================
// ================== Program Entry ===================
// ====================================================
//
void unitTest1() {
	// Pushing front on empty and on partial list
	printf("Printing TEST 1\n\n");
        dll_t * dll = create_dll();
        if (dll_push_front(dll, 1) == -1) {
                printf("This is NULL\n\n");

        } else {
                printf("This test passed\n\n");

        }

	free_dll(dll);	

}


void unitTest2() {
	
	// Pushing on NULL list
	dll_t * testNull = NULL;

	printf("Test 2: pushing NULL\n\n");
	if (dll_push_front(testNull, 1) == -1) {
                printf("This test passed.\n\n");
        } else if (dll_push_front(testNull, 0)) {
                printf("This test failed\n\n");

        } else {
                printf("This test failed\n\n");
        }
        free_dll(testNull);
}


void unitTest3() {
	// Pushing back on empty and partial list
	printf("Printing TEST 3\n\n");
        dll_t * dll = create_dll();
	if (dll_push_back(dll, 1) == -1) {
		printf("This is NULL\n\n");

	} else {
		printf("This test passed\n\n");

	}
	free_dll(dll);
}


void unitTest4() {
        printf("Printing TEST 4\n\n");
        dll_t * testNull = NULL;
        if (dll_push_back(testNull, 1) == -1) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n\n");

        }
        free_dll(testNull);
}




int main(){
	
	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();


	return 0;
}

