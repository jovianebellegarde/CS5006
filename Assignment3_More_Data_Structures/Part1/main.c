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

	dll_t * dll = create_dll();

        if (dll_empty(dll)) {
        printf("This list is empty.\n\n");
	}
     
  	printf("Pushing forward: %d.\n\n", 1, dll_push_front(dll, 0));
	printf("Pushing forward: %d.\n\n", 2, dll_push_front(dll, 1)); 
	printf("Pushing forward: %d.\n\n", 3, dll_push_front(dll, 2));                                                          

	if (dll_empty(dll)) {
	printf("This list is empty.\n\n");

	} else {
		printf("This list is not empty.\n\n");
	}

	printf("Pushing back %d.\n\n", 4, dll_push_back(dll, 0));
	printf("Pushing back %d.\n\n", 5, dll_push_back(dll, 1));
	printf("Pushing back %d.\n\n", 6, dll_push_back(dll, 2));
	
		
	printf("The size of this list is %d.\n\n", dll_size(dll));
	
	printf("Popping off %d off the front.\n\n", dll_pop_front(dll));

	printf("Popping off %d off the back.\n\n", dll_pop_back(dll));
	free_dll(dll);

}





int main(){
	
	unitTest1();
	return 0;
}

