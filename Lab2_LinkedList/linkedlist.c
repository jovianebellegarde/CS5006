// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// Create your node_t type here
typedef struct node {
	struct node* next;
	int wins;
	int years;

}node_t;

node_t* create_list() {
	node_t *year2014 = malloc(sizeof(node_t));
    	node_t *year2013 = malloc(sizeof(node_t));
   	node_t *year2012 = malloc(sizeof(node_t));
   	node_t *year2011 = malloc(sizeof(node_t));
	node_t *year2010 = malloc(sizeof(node_t));
   	node_t *year2009 = malloc(sizeof(node_t));

	year2014->years = 2014;
   	year2013->years = 2013;
   	year2012->years = 2012;
   	year2011->years = 2011;
   	year2010->years = 2010;
   	year2009->years = 2009;

   	year2014->wins = 54;
   	year2013->wins = 80;
   	year2012->wins = 73;
   	year2011->wins = 84;
   	year2010->wins = 88;
    	year2009->wins = 83;

   	year2014->next = year2013;
   	year2013->next = year2012;
   	year2012->next = year2011;
   	year2011->next = year2010;
   	year2010->next = year2009;
	year2009->next = NULL;
	
	return year2014;
}		


void* print_list() {
	node_t* redSox = NULL;
    	redSox = create_list();
    	node_t* iterator = redSox;
    	while (redSox != NULL) {
		printf("%d, %d wins\n", redSox->years, redSox->wins);
        	redSox = redSox->next;
    	}	
    	free(redSox);
	return 0;
}

int main(){
	node_t* redSox = NULL;
	redSox = create_list();
	
	print_list();

  	return 0;
}

