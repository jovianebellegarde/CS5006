// =================== Support Code =================
// Graph.
//
//
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "my_dll.h"
#include <stdlib.h>
#include <assert.h>
// Create a graph data structure
typedef struct graph{
    int numNodes;
    int numEdges;
    dll_t* nodes;     //an array of nodes storing all of our nodes.
}graph_t;

typedef struct graph_node{
    int data;
    dll_t* inNeighbors;
    dll_t* outNeighbors;
}graph_node_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
// Returns NULL if we cannot allocate memory.
graph_t* create_graph(){
    // Modify the body of this function as needed.
    graph_t* myGraph= malloc(sizeof(graph_t));
    
    myGraph->nodes = create_dll();
	if(myGraph == NULL) {
		return NULL;
	}
    myGraph->numEdges = 0;
    myGraph->numNodes = 0;

    myGraph->nodes = create_dll();
    return myGraph;
}

//Returns the node pointer if the node exists.
//Returns NULL if the node doesn't exist or the graph is NULL
graph_node_t* find_node( graph_t * g, int value){
	
	if (g == NULL) {
		return NULL;
	
	}
	
	node_t* tempNode = g->nodes->head;
	
	// while not end of the list
	while (tempNode != NULL) {
	
	// graph_node_t* node = (graph_node_t*) iterator->data;
	graph_node_t* node = (graph_node_t*) tempNode->data;
	if (tempNode->data == value) {
                return tempNode;
        }

	//iterator = iterator->next;
	tempNode = tempNode->next;	
	}

	return NULL;
}

graph_node_t * create_graph_node(int value){
    graph_node_t * graph_node = malloc(sizeof(graph_node));
    
    if ( graph_node == NULL ) return NULL;
    
    graph_node->data = value;
    graph_node->inNeighbors = create_dll();
    graph_node->outNeighbors = create_dll();

    return graph_node;
}

//Returns 1 on scucess
//Returns 0 on failure ( or if the node already exists )
//Returns -1 if the graph is NULL.
int graph_add_node(graph_t* g, int value){
    if ( g == NULL ) return -1;
    
    if (find_node(g, value) != NULL) return -1;
    
    graph_node_t * newNode = create_graph_node(value);
    if ( newNode == NULL ) return -1;
    
    assert(g->nodes);
    dll_push_back(g->nodes, newNode);
    g->numNodes++;
    
    return 1;
}

//Returns 1 on success
//Returns 0 on failure ( or if the node doesn't exist )
//Returns -1 if the graph is NULL.
int graph_remove_node(graph_t* g, int value){
    //The function removes the node from the graph along with any edges associated with it.
    //That is, this node would have to be removed from all the in and out neighbor's lists that countain it.
    	if (g == NULL) {
        	return -1;	
    	}  
	
	if (find_node(g, value) == NULL) {
		return -1;
	}
	
	dll_remove(g->nodes, value);
	g->numNodes--;
	
	return 1;
}

//Returns 1 on success
//Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge already exists )
//Returns -1 if the graph is NULL.
int graph_add_edge(graph_t * g, int source, int destination){
    //The function adds an edge from source to destination but not the other way.
    //Make sure you are not adding the same edge multiple times.
    //Make sure you modify the in and out neighbors appropriatelly. destination will be an out neighbor of source.
    //Source will be an in neighbor of destination.
    	if (g == NULL) {
		return -1;
	}

	while (g != NULL) {

		graph_node_t* sourceNode = find_node(g, source);
        	graph_node_t* destNode = find_node(g, destination);
        	if ((sourceNode == NULL) || (destNode == NULL)) {
                	return 0;
        	}

		// Checking to see if destination node is on inNeighbors list
		// Checking to see if the node for the inNeighbor is on the outNeighbors list
		int inNode;
		int outNode;

		inNode = dll_find(destNode->inNeighbors, sourceNode);
		outNode = dll_find(destNode->outNeighbors, destNode);
		
		// If there is an out neighbor or in neighbor edge that exits, return 1
		if (outNode == 1 || inNode == 1) {
			return 1;
		}
		g->numEdges++;
		g->nodes++;
				
		// If returning 1, successfully added nodes since the edges for inNeighbor and outNeighbor are on each other's lists
		return (dll_push_back(destNode->inNeighbors, source) && dll_push_back(sourceNode->outNeighbors, destination));
	}
	return 0;
}

//Returns 1 on success
//Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge doesn't exists )
//Returns -1 if the graph is NULL.
int graph_remove_edge(graph_t * g, int source, int destination){
    //The function removes an edge from source to destination but not the other way.
    //Make sure you remove destination from the out neighbors of source.
    //Make sure you remove source from the in neighbors of destination.
    	if (g == NULL) {
		return -1;
	}

	while (g != NULL) {

		graph_node_t* sourceNode = find_node(g, source);
        	graph_node_t* destNode = find_node(g, destination);
        	if ((sourceNode == NULL) || (destNode == NULL)) {
                	return 0;
        	}
		
		int inNode;
        	int outNode;

        	inNode = dll_find(destNode->inNeighbors, sourceNode);
        	outNode = dll_find(sourceNode->outNeighbors, destNode);

        	if (outNode == 1 || inNode == 1) {
                	return 1;
        	}

        	g->numEdges--;
        	g->nodes--;
        	return (dll_remove(destNode->inNeighbors, source) && dll_remove(sourceNode->outNeighbors, destination));

	}
	return 0;
}

//Returns 1 on success
//Returns 0 on failure ( or if the source or destination nodes don't exist )
//Returns -1 if the graph is NULL.
int contains_edge( graph_t * g, int source, int destination){
	if (g == NULL) {
		return -1;
	}

	graph_node_t* sourceNode = find_node(g, source);
	graph_node_t* destNode = find_node(g, destination);

	if ((sourceNode == NULL) || (destNode == NULL)) {	
		return 0;
	} 	

	while (g != NULL) {

		graph_node_t* sourceNode = find_node(g, source);
        	graph_node_t* destNode = find_node(g, destination);

        	if ((sourceNode == NULL) || (destNode == NULL)) {
                	return 0;
        	}
		int inNode;
        	int outNode;

        	outNode = dll_find(sourceNode->outNeighbors, destNode);
        	inNode = dll_find(destNode->inNeighbors, sourceNode);

        	if (inNode == 1) {
                	return 1;
        	} 

        	if (outNode == 1) {
                	return 1;
        	}

        	return 0;
	}
}

//Returns dll_t* of all the in neighbors of this node.
//Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getInNeighbors( graph_t * g, int value ){

	if (g == NULL) {
		return NULL;
	}

	graph_node_t* node = find_node(g, value);
	
	if (node == NULL) {
		return NULL;
	}
	return node->inNeighbors;	
}

//Returns the number of in neighbors of this node.
//Returns -1 if the graph is NULL or the node doesn't exist.
int getNumInNeighbors( graph_t * g, int value){
	if (g == NULL) {
                return NULL;
        }

        graph_node_t* node = find_node(g, value);

        if (node == NULL) {
                return NULL;
        }
        return node->inNeighbors->count;

}

//Returns dll_t* of all the out neighbors of this node.
//Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getOutNeighbors( graph_t * g, int value ){
    
	if (g == NULL) {
		return NULL;
	}

	graph_node_t* node = find_node(g, value);

	if (node == NULL) {
		return NULL;
	}

	return node->outNeighbors;

}

//Returns the number of out neighbors of this node.
//Returns -1 if the graph is NULL or the node doesn't exist.
int getNumOutNeighbors( graph_t * g, int value){

	if (g == NULL) {
		return NULL;
	}

	graph_node_t* node = find_node(g, value);

	if (node == NULL) {
		return NULL;
	}

	return node->outNeighbors->count;
}

// Returns the number of nodes in the graph
// Returns -1 if the graph is NULL.
int graph_num_nodes(graph_t* g){
	if (g == NULL) {
		return NULL;
	}
	return g->numNodes;
}

// Returns the number of edges in the graph,
// Returns -1 on if the graph is NULL
int graph_num_edges(graph_t* g){
       	if (g == NULL) {
             return NULL;
        }
        return g->numEdges;
}

//Returns 1 if reachable
//Returns 0 if not reachable.
//Returns -1 if the graph is NULL or if either of the nodes doesn't exist.
int is_reachable(graph_t * g, int source, int dest){
    //Implement using BFS.
    //Make sure you don't get stuck into an infinite loop.
 	if (g == NULL) {
		return -1;
	}   
		
	graph_node_t* destNode = find_node(g, dest);
        graph_node_t* sourceNode = find_node(g, source);
        if (sourceNode == NULL || destNode == NULL) {
                return 0;
		
	}
	
	// Creating 2 dlls
	// These dlls keep track of which node we visted and which ones we didn't visit
	dll_t* visited = create_dll();
        dll_t* unvisited = create_dll();
	
	// Pushing source node from the back of unvisited dll to the back of the visited dll
	dll_push_back(unvisited, sourceNode);

	// While the unvisted list of nodes is not empty, continue looping through
	while (dll_empty(unvisited) != 1) {
	
		// Saving the node from the visited list
		graph_node_t* node = dll_push_front(unvisited, sourceNode);

		// Pushing the node from the back of the unvisited dll to the back fo the visted dll
		dll_push_back(visited, node);


		// Checking to see if we've arrived at the destination
		if (node->data == dest) {
			return 1;
		}

		// Iterating through the node through the outNeighbor list
		node_t* iterator = node->outNeighbors->head;
		
		while (iterator != NULL) {
			graph_node_t* graphNode = (graph_node_t*) iterator->data;

			// These lines of code is for the BFS
			// If the node has not yet visited, will not find in visited dll list
			// Add the node to the unvisited list if not yet visited
			if (dll_find(visited, graphNode) == 1) {
				dll_pop_front(unvisited);
			
			}							
			iterator = iterator->next;


		}
		
			
							

	}	
	return 0;
}


static int is_reachable_dfs(graph_t* g, int source, int dest) {
	if (g == NULL) {
		return -1;
	}
	
	graph_node_t* destNode = find_node(g, dest);
	graph_node_t* sourceNode = find_node(g, source);
	if (sourceNode == NULL || destNode == NULL) {
		return 0;
	}
	/*
	graph_node_t* destNode = find_node(g, dest);
	if (destNode == NULL) {
		return 0;
	}
	*/
	
	// Create 2 dlls
	// These dlls keep track of which we visited and which ones we didn't visit
	dll_t* visited = create_dll();
	dll_t* unvisited = create_dll();
	
	// push the source node on to the back of the unvisited list
	dll_push_back(unvisited, sourceNode);
	
	// while the unvistied list of nodes is not empty, continue looping through
	while (dll_empty(unvisited) != 1) {
	
		// save the node from visited list 
		graph_node_t* node = dll_pop_back(unvisited);
	
		// push the node from back of unvisited dll to the back of the visted dll
		dll_push_back(visited, node);

		// check to see if arrived at dest node
		// dest is parameter that was passed in
		if (node->data == dest) {
			return 1;
		}	
	
		// Iterate through node outNeighbor list
		node_t* iterator = node->outNeighbors->head;
	
		while (iterator != NULL) {
	
			graph_node_t* graphNode = (graph_node_t*) iterator->data;
	
			// Next line of code differentiates DFS from BFS
			// If node not yet visited, will not find in visited dll
			// Add the node to unvisited list if not visited yet
			if (dll_find(visited, graphNode) != 1) {
				dll_push_back(unvisited, graphNode);

			}

			iterator = iterator->next;
		}
	
	}
	return 0;

}



//Returns 1 if the graph has a cycle.
//Returns 0 if the graph doesn't have a cycle.
//Returns -1 if the graph is NULL or if either of the nodes doesn't exist.
int has_cycle(graph_t * g){
    //Implement using DFS.
    //Make sure you don't get stuck into an infinite loop.
    if (g == NULL) {
	return -1;
	}

	node_t* iterator = g->nodes->head;
	
	// looking for while loop
	// this while loops iterates through the mater list of graph nodes
	while (iterator != NULL ) {

		graph_node_t* node = (graph_node_t*) iterator->data;
		
		// this 2nd while loop iterates through each graph nodes' inNeighbors list
		// cycle exists if a graph node as itself inNeighbors list
		// the inNeihbors list is the list of all nodes pointing to graph node
		// this line iterators through a dll inside the graph node	
		node_t* inNeighborsIterator = node->inNeighbors->head;
		
		while (inNeighborsIterator != NULL) {
			
			// Saving the origin node to pass a parameter into is reachable DFS and see if it comes back to itself
			graph_node_t* originNode = (graph_node_t*) inNeighborsIterator->data;
			
			// if the node can reach itself it has a cycle
			// ifi checking to see if the graph has a cycle, can return 1 the first time we find a cycle
			if (is_reachable_dfs(g, node->data, originNode->data) == 1) {
				return 1;
			}
			// Keep iteratoring through inNeigh dll
			inNeighborsIterator = inNeighborsIterator->next;	
		}
		// still need to iterator through master list of graph nodes (dll nodes)	
		iterator = iterator->next;
	}
	return 0;
}
//Prints all the nodes from source to destination ( including the source and destination),
//i.e. print_path(1,5) => 1 2 3 4 5
//otherwise it prints "path does not exit" or if source or dest nodes do not exist or if the graph is NULL.
void print_path(graph_t * g, int source, int dest){
    printf("Path does not exist\n");
}

// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the proram terminates.
// Make sure you free all the dll's too.
void free_graph(graph_t* g){
	if (g == NULL) {
		return;
	}

	node_t* tempNode = g->nodes->head;
	while (tempNode != NULL) {
		graph_node_t* node = (graph_node_t*) tempNode->data;
		free_dll(node->inNeighbors);
		free_dll(node->outNeighbors);
		free(node);
		tempNode = tempNode->next;
	}
	free_dll(g->nodes);
	free(g);
}



#endif
