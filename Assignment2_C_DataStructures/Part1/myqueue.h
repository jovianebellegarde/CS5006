// =================== Support Code =================
// Queue
//
//
//
// - Implement each of the functions to create a working circular queue.
// - Do not change any of the function declarations
//   - (i.e. queue_t* create_queue(unsigned int _capacity) should not have additional arguments)
// - You should not have any 'printf' statements in your queue functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <stdlib.h>

// The main data structure for the queue
struct queue{
	unsigned int back;  // The next free position in the queue
			    	// (i.e. the end or tail of the line)
	unsigned int front; // Current 'head' of the queue
				// (i.e. the front or head of the line)
	unsigned int size; // How many total elements we currently have enqueued.
	unsigned int capacity;  // Maximum number of items the queue can hold
	int* data; 		// The 'integer' data our queue holds	
};
// Creates a global definition of 'queue_t' so we 
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on the heap.
// If you weren't able to allocate memory, return NULL.
queue_t* create_queue(unsigned int _capacity){
	
	// Allocating space for myQueue
	queue_t* myQueue = (queue_t*)malloc(sizeof(queue_t));
	
	// Checking to see if the value assigned to myQueue is NULL
	if (myQueue == NULL) { 
		return NULL;
	}
	// Setting initial values for myQueue
	myQueue->back = 0;
	myQueue->front = 0;
	myQueue->size = 0;
	myQueue->capacity = _capacity;

	// Allocating space for data in myQueue
	myQueue->data = (int*)malloc(_capacity * sizeof(int));
	
	// Checking to see if the data is NULL
	if(myQueue->data == NULL) {
		return NULL;
	} 
	return myQueue;
}

// Queue Empty
// Check if the queue is empty
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has at least one element enqueued)
// Returns -1 if the queue is NULL
int queue_empty(queue_t* q){
	
	// Checking to see if the queue is assigned to NULL
	if (q == NULL) {
		return -1;
	
	// Checking to see if the queue is completely empty
	} else if(q->size == 0) {
		return 1;

	// Returning 0 because the queue is not completely empty	
	} else {
		return 0;

	}	
}

// Queue Full
// Check if the queue is Full
// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available to enqueue items)
// Returns -1 if the queue is NULL.
int queue_full(queue_t* q){
	
	// Checking to see if the queue is assigned NULL
	if (q == NULL) {
		return -1;
	
	// Checking to see if the queue is completely full
	} else if (q->size == q->capacity) {
		return 1; 

	// Returning 0 if the queue has more space avaialable 
	} else {
		return 0;
	}
}	

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a 1 if the operation suceeds
// Returns a 0 if the operation fails 
// Returns -1 if the queue is NULL.
// (i.e. if the queue is full that is an error).
int queue_enqueue(queue_t* q, int item){
	
	// Checcking to see if myQueue has space to enqueue an item
	if (q == NULL) {
		return -1;
	
	} else if (queue_full(q)) {
		return 0;
	
	} else {
		// Enqueue item
		q->data[q->back] = item;

		// Updating the queue's back b/c we added an item to the back
		q->back = (q->front + 1) % q->capacity;

		// Increasing the size of the queue since adding item
		q->size++;

		return 1;
	}
}
// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
// Removing from an empty gueue should return 0 // assume all entries are going to be > 0.
// Returns -1 if the queue is NULL. Assumption there is not going to be negative numbers in the queue
int queue_dequeue(queue_t *q){
	
	// Checking to see if the queue is assigned a NULL value
	if (q == NULL) {
		return -1;
	
	// Checking to see that the queue is empty before attempting to remove
	// from an empty queue 
	} else if (queue_empty(q)) {
		return -1;
	
	} else {
		// Creating a variable to save what is being removed from front
		int tempFront = q->data[q->front];
		
		// Updating the queue's front b/c we removed an item from the front
		q->front = (q->front + 1) % q->capacity;
		
		// Decreasing the size since the front was removed
		q->size--;

		return tempFront;
	}
}


// Queue Size
// Queries the current size of a queue
// Returns -1 if the queue is NULL.
unsigned int queue_size(queue_t* q){

	// Checking to see if there is a NULL value
	if (q == NULL) {
		return -1;

	} else {
		return q->size;
	}
}

// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the proram terminates.
void free_queue(queue_t* q){
	
	// If the value assigned to the queue is not NULL, then we can free
	// the data insde the queue and the entire queue
	if (q != NULL) {
	free(q->data);
	free(q);
	}
}


#endif
