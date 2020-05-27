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
        } else if (dll_push_front(testNull, 1)) {
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


void unitTest5() {
	//Partial pop front
	printf("Printing TEST 5 - Popping front partial\n\n");
        dll_t * dll = create_dll();
        dll_push_front(dll, 1);
	dll_push_front(dll, 1);
	if (dll_pop_front(dll) == -1 || dll_pop_front == 0) {
		printf("this test failed.\n\n");

	} else {
		printf("This test passed.\n\n");
        free_dll(dll);
	}	


}

void unitTest6() {
	// Empty pop front
	printf("Printing TEST 6 - Popping front empty\n\n");
        dll_t * dll = create_dll();
        if (dll_pop_front(dll)== 0) {
                printf("This test passed\n\n");

        } else {
		printf("This test failed\n\n");
	}
        free_dll(dll);
}

void unitTest7() {
	// NULL pop front 
	printf("Printing TEST 7 - Popping front NULL\n\n");
        dll_t * testNull = NULL;
        if (dll_pop_front(testNull) == -1) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n\n");
        }
        free_dll(testNull);


}


void unitTest8() {
	printf("Printing TEST 8 - Popping back partial\n\n");
        dll_t * dll = create_dll();
	dll_push_back(dll, 1);
	dll_push_back(dll, 1);
        if (dll_pop_back(dll) == -1 || dll_pop_back(dll)== 0)  {
                printf("This test failed\n\n");

        } else {
                printf("This test passed\n\n");
        }
        free_dll(dll);

}

void unitTest9() {
	printf("Printing TEST 9 - Popping back empty\n\n");
        dll_t * dll = create_dll();  
        if (dll_pop_back(dll) == 0) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(dll);

}

void unitTest10() {
	printf("Printing TEST 10 - Popping back NULL\n\n");
        dll_t * testNull = NULL;
	dll_push_back(testNull, 1);
	dll_push_back(testNull, 1);
        if (dll_pop_back(testNull) == -1) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(testNull);

}

void unitTest11() {
        printf("Printing TEST 11 - Inserting partial\n\n");
        dll_t * dll = create_dll();
        dll_push_front(dll, 1);
        dll_push_back(dll, 1);
        if (dll_insert(dll, 1, 2) != -1 || dll_insert(dll, 1, 2) != 0 
		|| dll_insert(dll, 1, 2) != 1) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(dll);

}

void unitTest12() {
        printf("Printing TEST 12 - Inserting empty\n\n");
        dll_t * dll = create_dll();
        if (dll_insert(dll, 1, 2) == 0) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(dll);

}


void unitTest13() {
	printf("Printing TEST 13 - Inserting NULL\n\n");
        dll_t * testNull = NULL;
        if (dll_insert(testNull, 1, 2) == -1) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(testNull);

}


void unitTest14(){
	printf("Printing TEST 14 - Getting partial\n\n");
        dll_t * dll = create_dll();
	dll_push_front(dll, 1);
	dll_push_back(dll, 1);
        if (dll_get(dll, 1) != 0 || dll_get(dll, 1) != -1) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(dll);	

}


void unitTest15() {
	printf("Printing TEST 15 - Getting empty\n\n");
        dll_t * dll = create_dll();
        if (dll_get(dll, 1) == 0) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(dll);

}

void unitTest16() {
	printf("Printing TEST 16 - Getting NULL\n\n");
        dll_t * testNull = NULL;
        dll_push_front(testNull, 1);
        dll_push_back(testNull, 1);
        if (dll_get(testNull, 1) == -1) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(testNull);

}

void unitTest17() {
	printf("Printing TEST 17 - Removing partial\n\n");
        dll_t * dll = create_dll();
        dll_push_front(dll, 1);
        dll_push_back(dll, 1);
        if (dll_remove(dll, 0) != 0 || dll_get(dll, 0) != -1) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(dll);

}

void unitTest18() {
	printf("Printing TEST 18 - Removing empty\n\n");
        dll_t * dll = create_dll();
        if (dll_remove(dll, 0) == 0) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(dll);

}

void unitTest19() {
	printf("Printing TEST 19 - Removing NULL\n\n");
        dll_t * testNull = NULL;
        dll_push_front(testNull, 1);
        dll_push_back(testNull, 1);
        if (dll_remove(testNull, 0) == -1) {
                printf("This test passed\n\n");

        } else {
                printf("This test failed\n");
        }
        free_dll(testNull);

}

int main(){
	
	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();
	unitTest5();
	unitTest6();
	unitTest7();
	unitTest8();
	unitTest9();
	unitTest10();
	unitTest11();
	unitTest12();
	unitTest13();
	unitTest14();
	unitTest15();
	unitTest16();
	unitTest17();	
	unitTest18();
	unitTest19();
	return 0;
}

