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

	printf("total nodes: 3 == %d\n\n", graph_num_nodes(partialGraph));
	
	return 0;

}




int main(int argc, const char * argv[]) {
    /*
    graph_t * graph = create_graph();
    graph_add_node(graph, 1);
    graph_add_node(graph, 1);
    graph_add_node(graph, 2);
    printf("total nodes: 2 == %d\n", graph_num_nodes(graph));
    return 0;
    */

	unitTest1();
	
	return 0;

}
