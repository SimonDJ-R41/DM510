#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

graph *read_graph(char *filename) {
	FILE *fp = fopen(filename, "r");	// opens the files in read-only mode

	char *lines = NULL;
	size_t pos = 0;

	getline(&lines, &pos, fp);				// reads the first line

	const size_t size = strtol(lines, NULL, 10);
	/*
	long int strtol(const char *str, char **endptr, int base)
	char **endptr not required for the required task
	*/

	vertex *array = calloc(size, sizeof(*array));

	for(size_t i = 0; i < size; i++) {
		getline(&lines, &pos, fp);
		for(size_t j = 0; j < size; j++) {
			if('1' == lines[j]) {
				if(array[i].out_neighbours) {
					add_element(array[i].out_neighbours, array + j);
				} else {
					array[i].out_neighbours = init_linked_list();
					array[i].out_neighbours->data = array + j;
				}
				if(array[j].in_neighbours) {
					add_element(array[j].in_neighbours, array + i);
				} else {
					array[j].in_neighbours = init_linked_list();
					array[j].in_neighbours->data = array + i;
				}
			}
		}
	}

	fclose(fp);
	free(array);

	return NULL;
}

void print_graph(graph *g) {

	for(int i = 0; i < SIZE?; i++) {
		printf("%d%s", INSERT NUMBER, list->next ? ", " : "\n");
	}
}
