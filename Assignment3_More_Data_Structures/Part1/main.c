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
	char a = 'A';
	char b = 'B';
	char c = 'C';
	char d = 'D';
	char e = 'E';

	dll_t * dll = create_dll();

        if (dll_empty(dll)) {
        printf("This list is empty.\n\n");
	}
     
  	printf("Pushing forward: %c.\n\n", a, dll_push_front(dll, 1));
	printf("Pushing forward: %c.\n\n", b, dll_push_front(dll, 2)); 
	printf("Pushing forward: %c.\n\n", c, dll_push_front(dll, 3));                                                          

	if (dll_empty(dll)) {
	printf("This list is empty.\n\n");

	} else {
		printf("This list is not empty.\n\n");
	}
	
	printf("The size of this list is %d.\n\n", dll_size(dll));

	printf("Pushing back %c.\n\n", d, dll_push_back(dll, d));
	printf("Pushing front %c.\n\n", e, dll_push_front(dll, e));
	
		
	printf("The size of this list is %d.\n\n", dll_size(dll));
	
	printf("Popping %c off the front.\n\n", dll_pop_front(dll));

	printf("Popping %c off the back.\n\n", dll_pop_back(dll));
	
	printf("The size of the is list is %d.\n\n", dll_size(dll));

	printf("Inserting D at position %d.\n\n", dll_insert(dll, 0, d));
	printf("The size of this list is %d.\n\n", dll_size(dll));

	printf("Removing D at position %d.\n\n", dll_get(dll, 0));


	free_dll(dll);


}





int main(){
	
	unitTest1();
	return 0;
}

