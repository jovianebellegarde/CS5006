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
	unsigned int back;	    // The next free position in the queue
				                  // (i.e. the end or tail of the line)
	unsigned int front;	    // Current 'head' of the queue
				                  // (i.e. the front or head of the line)
	unsigned int size;	    // How many total elements we currently have enqueued.
	unsigned int capacity;  // Maximum number of items the queue can hold
	int* data; 		          // The 'integer' data our queue holds	
};
// Creates a global definition of 'queue_t' so we 
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on the heap.
// If you weren't able to allocate memory, return NULL.
queue_t* create_queue(unsigned int _capacity){
	queue_t* myQueue = (queue_t*)malloc(sizeof(queue_t));
	if (myQueue == NULL) {
		return NULL;
	}	
	// Setting initial values for the queue
	myQueue->back = 0;
	myQueue->front = 0;
	myQueue->size = 0;
	myQueue->capacity = _capacity;
	
	// Allocating space for the data
	myQueue->data = (int*)malloc(_capacity * sizeof(int));
	if (myQueue->data == NULL) {
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
	if (q->size == 0) {
		return 1;
	
	} else if (q == NULL) {
		return -1;
		
	} else if (q == NULL) {
	 	return -1;

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
	if (q-> size == q->capacity){
		return 1;
	
	} else if (q == NULL) {
		return -1;

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
	if (q->size == q->capacity) {
		return 0;

	} else if (q == NULL) {
		return -1;

	} else {
		// Enqueue item
		q->data[q->back] = item;
		
		// Updating the queue's back
		q->back = (q->back +1) % q->capacity;
		
		// We are increasing the size of the queue
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
	if (q->size == 0) {
		return 0;
	
	} else if (q == NULL) {
		return -1;

	} else {
		// Creating temp variable
		int tempFront = q->data[q->front];
		
		// Removed item in front of queue, and now have next item first
		q->front = (q->front + 1) % q->capacity;
		q->size--;
	
		return tempFront;
	}	
}
// Queue Size
// Queries the current size of a queue
// Returns -1 if the queue is NULL.
unsigned int queue_size(queue_t* q){
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
	if (q != NULL) {
	// Free the queue's data
	free(q->data);
	/*
 	 * Free the q after freeing the data sot hat we can actually access
 	 * the data.
 	 */
	free(q); 
	}
}


#endif
