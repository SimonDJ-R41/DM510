#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "cycledetection.h"

/*
 * Prints the usage to the console.
 */
void show_usage() {
	printf("===================================\n");
	printf("=======     Usage      ============\n");
	printf("===================================\n");
	printf(" ./program graph-file \n");
	printf("===================================\n");
}

// First command line parameter - input file
int main(int argc, char *argv[]) {


	// // Error checking
	// if( argc != 2) {
	// 	show_usage();
	// 	return 0;
	// }
  //
	// // Build a graph from the input
	// graph *g = read_graph(argv[1]);
  //
	// // Run cycle detection algorithm and output result
	// cycle_detection(g);

	linked_list * mystacklist = init_linked_list();

  int a = 5, b = 6, c = 7, d = 8;

  add_element(mystacklist, &a);
  add_element(mystacklist, &b);
	add_element(mystacklist, &c);
	add_element(mystacklist, &d);

  remove_first(&mystacklist);
}
