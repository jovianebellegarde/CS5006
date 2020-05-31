// =================== Support Code =================
// Binary Search Tree ( BST ).
//
//
//
// - Implement each of the functions to create a working BST.
// - Do not change any of the function declarations
//   - (i.e. bst_t* create_bst() should not have additional arguments)
// - You should not have any 'printf' statements in your BST functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYBST_H
#define MYBST_H

// Create a node data structure to store data within
// our BST. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* rightChild;
  	struct node* leftChild;
}node_t;

// Create a BST data structure
// Our BST holds a pointer to the root node in our BST called root.
typedef struct BST{
	int count;		// count keeps track of how many items are in the BST.
	node_t* root;		// root points to the root node in our BST.
}bst_t;

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values.
// Return NULL if we couldn't allocate memory for the BST.
bst_t* create_bst(){
	// Modify the body of this function as needed.
	bst_t* myBST = (bst_t*) malloc(sizeof(bst_t));

	if (myBST == NULL) {
	return NULL;
	}	
	
	myBST->count = 0;
	myBST->root = NULL;

	return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element enqueued)
// Returns -1 if a NULL is passed to the function
// Should run in constant time.
int bst_empty(bst_t* t){
	
	if (t === NULL) {
		return -1;
	}

	if (t->count == 0) {
		return 1;
	}
	
	return 0;
}

// Adds a new node containng item in the correct place of the BST.
// If the data is less then the current node we go left, otherwise we go right.
// Returns 1 if the operation suceeds
// Returns 0 if the operation fails ( we couldn't allocate enough memory for the new node)
// Returns -1 of NULL tree has been passed in. 
// It should run in O(log(n)) time.
int bst_add(bst_t* t, int item){	
	if (t == NULL) {
        	return -1;
    	}

    	node_t* tempNode = (node_t*) malloc(sizeof(node_t));
    	if(tempNode == NULL) {
        	return -1;
    	}

    	if (bst_empty(t) == 1) {
        	t->root = tempNode;
        	t->count++;
        	return 1;

    	} else {
        	int feedback = 0;
        	feedback = bstHelperAdd(t->root, tempNode);
        	if (feedback == 0) {
            		t->count++;
            		return 1;
        	}

	        return 0;	
    	}	
	return 0;
    
}

int bstHelperAdd(node_t* root, node_t* newNode) {
	// Check if duplicate data
	if (root->data == newNode->data) {
        	free(newNode);
        	return 1;
    	}

    	if (root->data > newNode->data) {
        	if (root->leftChild == NULL) {
            		root->leftChild = newNode;
            		return 0;

        	} else {
            	bstHelperAdd(root->leftChild, newNode);
        	}	

    	} else {
        	if (root->rightChild == NULL) {
            	root->rightChild = newNode;
            	return 0;

        	} else {
            		bstHelperAdd(root->rightChild, newNode);
        	}
    	}

}


// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree it should print nothing. 
// It should run in O(n) time.
void bst_print(bst_t*t, int order){
	
}

// Returns the sum of all the nodes in the tree. 
// Returns 0 for an empty tree.
// Returns -1 if a NULL tree is passed to the function.
// It should run in O(n) time.
int sum(bst_t *t){
  return 0;
}

// Returns 1 if value is found in the tree.
// Returns 0 if the value is not found in three.
// Returns -1 if a NULL tree has been passed to the function
// It should run in O(log(n)) time.
int find(bst_t * t, int value){
  return 0;
}

// BST Size
// Queries the current size of the BST
// Returns the size of the tree.
// Returns -1 if a NULL tree has been passed in.
// Should run in constant time.
unsigned int bst_size(bst_t* t){
	return 0;
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_bst(bst_t* t){

}



#endif
