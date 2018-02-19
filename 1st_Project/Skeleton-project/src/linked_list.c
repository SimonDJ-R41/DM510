/*
 * linked_list.c
 *
 *  Created on: Dec 24, 2013
 *      Author: jacob
 */
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

linked_list *init_linked_list() {

	linked_list *root = malloc(sizeof(linked_list));
	root -> data = NULL;
	root -> next = NULL;
	root -> previous = NULL;
	root -> size = 0;
	return root;
}

void add_element(linked_list *list, void *element) {

	linked_list *new_Node = malloc(sizeof(linked_list));
	new_Node -> data = element;
	linked_list *old = list -> previous ? list -> previous : list;
	/* Same as:
	if(list->previous) {
		linked_list *old = list->previous;
	} else {
		linked_list *old = list;
	}
	*/
	old -> next = old;
	list -> previous = new_Node;
	new_Node -> next = list;
	list -> size++;
}

int linked_list_size(linked_list *list) {
	return list -> size;
}

void *remove_first(linked_list *list) {
	return NULL;
}

int remove_element(linked_list *list, void *element) {
	return -1;
}
