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
int main(){
	dll_t * dll = create_dll();
	
	if (dll_empty(dll)) {
        printf("This list is empty.\n\n");
    	
	}	
	
	// Pushing 10 nodes to the front
	printf("Pushing forward: %d.\n\n", 1, dll_push_front(dll,0));
	
    	printf("Pushing forward: %d.\n\n", 2, dll_push_front(dll, 1));
    	printf("Pushing forward: %d.\n\n", 3, dll_push_front(dll, 2));
    	printf("Pushing forward: %d.\n\n", 4, dll_push_front(dll, 3));
    	printf("Pushing forward: %d.\n\n", 5, dll_push_front(dll, 4));
    	printf("Pushing forward: %d.\n\n", 6, dll_push_front(dll, 5));
    	printf("Pushing forward: %d.\n\n", 7, dll_push_front(dll, 6));
    	printf("Pushing forward: %d.\n\n", 8, dll_push_front(dll, 7));
    	printf("Pushing forward: %d.\n\n", 9, dll_push_front(dll, 8));
    	printf("Pushing forward: %d.\n\n", 10, dll_push_front(dll, 9)); 
	
//	printf("Inserting: ",  dll_insert(dll, 5, 78));

    
//	printf("Popping back: %d.\n", dll_pop_back(dll));

	printf("The size of the is is %d.\n\n", dll_size(dll));


	free(dll);
	return 0;

}
