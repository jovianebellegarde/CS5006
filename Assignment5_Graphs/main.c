// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_graph.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

void unitTest1() {

	graph_t* partialGraph = create_graph();
	graph_add_node(partialGraph, 1);
	graph_add_node(partialGraph, 2);
	graph_add_node(partialGraph, 3);
	
	printf("Testing find node\n\n");
		if (find_node(partialGraph, 2) == NULL) {
			printf("This partial graph is NULL\n\n");

		} else {
			printf("Found %d\n\n", 2);
		}
	
	printf("Total nodes: 3 == %d\n\n", graph_num_nodes(partialGraph));	
	printf("Has a cycle result: %d\n\n", has_cycle(partialGraph));
	printf("Adding an edge %d\n\n", graph_add_edge(partialGraph, 3, 2));
	graph_add_edge(partialGraph, 2, 1);
	graph_add_edge(partialGraph, 3, 2);
//	printf("Total number of edges: 2 == %d\n\n", graph_num_edges(partialGraph));

//	printf("Number of in neighbor nodes result: %d\n\n", getNumInNeighbors(partialGraph, 2));
//	printf("Number of out neighbor nodes result: %d\n\n", getNumOutNeighbors(partialGraph, 2));
//	printf("The number of graph nodes are %d\n\n", graph_num_nodes(partialGraph));
//	printf("Adding edge - result: %d\n\n", graph_add_edge(partialGraph, 1, 3));	
	

	free_graph(partialGraph);	
	return 0;

}

void unitTest2() {

	graph_t* testNull = NULL;
	graph_add_node(testNull, 1);
        graph_add_node(testNull, 2);
        graph_add_node(testNull, 3);

        printf("Testing find node\n\n");
        if (find_node(testNull, 2) == NULL) {
                        printf("This partial graph is NULL\n\n");

                } else {
                        printf("Found %d\n\n", 2);
                }

        printf("Total nodes: 3 == %d\n\n", graph_num_nodes(testNull));
        printf("Has a cycle result: %d\n\n", has_cycle(testNull));
        printf("Adding an edge %d\n\n", graph_add_edge(testNull, 3, 2));
        graph_add_edge(testNull, 2, 1);
        graph_add_edge(testNull, 3, 2);



	free_graph(testNull);
	return 0;
}

int main(int argc, const char * argv[]) {
	unitTest1();
	unitTest2();	
	return 0;

}
