// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
  	struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
	int count;		// count keeps track of how many items are in the DLL.
	node_t* head;		// head points to the first node in our DLL.
        node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t* create_dll(){
	// Modify the body of this function as needed.
	dll_t* myDLL = (dll_t*)malloc(sizeof(dll_t));
	
	if (myDLL == NULL) {
		return NULL;
    	}	
    	myDLL->count = 0;
    	myDLL->head = NULL;
    	myDLL->tail = NULL;	

	return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
// Returns -1 if the dll is NULL.
int dll_empty(dll_t* l){
	if (l == NULL) {
        	return -1;

    	} else if (l->count == 0) {
        	return 1;
    	}	
    	return 0;
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){
	if (l == NULL) {
        	return -1;
    	}	

    	node_t* pushFrontNode = (node_t*)malloc(sizeof(node_t));
    	if (pushFrontNode == NULL) {
        	return 0;
    	}

	if (dll_empty(l) == 1) {
        	l->head = pushFrontNode;
        	l->tail = pushFrontNode;
        	pushFrontNode->next = NULL;
        	pushFrontNode->previous = NULL;
        	pushFrontNode->data = item;
        	l->count++;
        	return 1;
	
	} 

	if (dll_empty(l) == 0) {
    
        	pushFrontNode->data = item;
        	pushFrontNode->next = l->head;
        	l->head = pushFrontNode;
        	pushFrontNode->previous = NULL;
        	l->count++;
        	return 1;
    	}
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){
	if (l == NULL) {
        return -1;
    	}	

    	node_t* pushBackNode = (node_t*)malloc(sizeof(node_t));
    	if (pushBackNode == NULL) {
        	return 0;
    	}	

    	if (l->count== 0) {
     		l->head = pushBackNode;
		l->tail = pushBackNode;
		pushBackNode->next = NULL;
		pushBackNode->previous = NULL;
		pushBackNode->data = item;
		l->count++;
		return 1;
	
	} else {	
	 	pushBackNode->next = NULL;
      
        	pushBackNode->data = item;
		l->tail->next = pushBackNode;
		pushBackNode->previous = l->tail;
		l->tail = pushBackNode;
		l->count++;
        	return 1;

	}
}
// Returns the first item in the DLL and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL. 
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t* t){
	if (t == NULL) {
        return -1;
    	}

    	if  (dll_empty(t) == 1) {
        	return 0;
    	}

    	int tempItem = t->head->data;
    	node_t* tempNode = t->head;

    	if (t->count == 1) {
        	t->head = NULL;
        	t->tail = NULL;

    	} else {

		t->head = t->head->next;
		t->head->previous = NULL;

	}
	t->count--;
	free(tempNode);
	return tempItem;
}


// Returns the last item in the DLL, and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL. 
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t* t){
	if (t == NULL) {
        return -1;
    	}	

    	if (dll_empty(t)) {
        	return 0;
    	}

    	int tempItem = t->tail->data;
    	node_t* tempNode = t->tail;

    	if (t->count == 1) {
        	t->head = NULL;
        	t->tail = NULL;

    	} else {
		t->tail = t->tail->previous;
		t->tail->next = NULL;

	}
	
	t->count--;
	free(tempNode);
	return tempItem;
}
// Inserts a new node before the node at the specified position.
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
// Returns -1 if the list is NULL
int dll_insert(dll_t* l, int pos, int item){
	if (l == NULL) {
        return -1;
    	}	

    	if (pos < 0 || pos > l->count) {
        	return 0;
    	}

    	if (pos == 0) {
		 dll_push_front(l, item);
		return 1;
    	}

	if (pos == l->count) {
		dll_push_back(l, item);
		return 1;
	}

	node_t* insertNode = (node_t*)malloc(sizeof(node_t));
        if (insertNode == NULL) {
                return -1;
        }

	insertNode->data = item;
    	node_t* tempNode = l->head;
    	int i = 0;
	for (i = 0; i < pos; i++) {
        	tempNode = tempNode->next;
    	}

	tempNode->previous->next = insertNode;
	insertNode->previous = tempNode->previous;
	tempNode->previous = insertNode;
	insertNode->next = tempNode;

}




// Returns the item at position pos starting at 0 ( 0 being the first item )
//  (does not remove the item)
// Retruns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t* l, int pos){
	if (l == NULL) {
        return -1;
    	}

    	if (pos >= l->count || pos < 0) {
        	return 0;
    	}
	node_t* tempNode = l->head;
	int i = 0;
	for (i = 0; i < pos; i++) {
        	tempNode = tempNode->next;
    	}
	return tempNode->data;
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Retruns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.
int dll_remove(dll_t* l, int pos){
	if (l == NULL) {
        return -1;
    	}

    	if (pos < 0 || pos >= l->count) {
        	return 0;
    	}

    	if (pos == 0) {
        	return dll_pop_front(l);
    	}

    	if (pos == l->count - 1) {
        	return dll_pop_back(l);
    	}

    	node_t* tempNode = l->head;
	int i = 0;
	for (i = 0; i < pos; i++) {
        	tempNode = tempNode->next;
    	}
	
	int tempItem = tempNode->data;
	tempNode->previous->next = tempNode->next;
	tempNode->next->previous = tempNode->previous;
    	free(tempNode);
    	return tempItem;
}

// DLL Size
// Queries the current size of a DLL
// Returns -1 if the DLL is NULL.
int dll_size(dll_t* t){
	if (t == NULL) {
        	return -1;
    	} else {
       	
	return t->count;
	}
}


// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
	if (t == NULL) {
        	return;
    	}
    	node_t* tempNode = t->head;
    	while(tempNode != NULL) {
        	node_t* nextNode = tempNode->next;
        	free(tempNode); 
		tempNode = nextNode;
    	}	
    	free(t);

}



#endif
