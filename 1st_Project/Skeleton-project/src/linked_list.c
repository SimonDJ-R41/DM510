/*
 * linked_list.c
 *
 *  Created on: Dec 24, 2013
 *      Author: jacob
 */
#include "linked_list.h"
#include <stdio.h>

linked_list *init_linked_list() {

	linked_list *root = malloc(sizeof(linked_list));
	root->data = NULL;
	root->next = NULL;
	root->previous = NULL;
	return root;
}

void add_element(linked_list *list, void *element) {

	linked_list *newNode = init_linked_list();				// initializes with a 'newNode'
	newNode->data = element;													// element given in argument goes to the data slot
	while(list->next) {																// while there's a next element present:
	 	list = list->next;															// list points to its next and sets itself there
	}

	list->next = newNode;															// sets the next-pointer from where list currently is, to the 'newNode'
	newNode->previous = list;													// sets the previous-pointer from 'newNode' to its previous
}

size_t linked_list_size(linked_list *list) {

	size_t i = 1;																			// counter for size
	while(list->next) {
		i++;																						// increments the size
		list = list->next;															// list is now placed at the next position
	}
	return i;																					// returns the size
}

void *remove_first(linked_list **list) {

	if(!(*list)) return NULL;													// if list is empty, return NULL
	linked_list *old = *list;													// creates a pointer, to maintain the other pointer 'list'
	void *data = old->data;														// data now points to the data of the node
	*list = old->next;																// 'list' is now pointing towards the 'old' pointers' next
	if(*list) (*list)->previous = old->previous;			// makes the 'list' pointer, now have its previous pointer to point towards NULL, instead of inaccessible memory
	free(old);																				// frees up 'old', since the pointers have now been updated
	return data;
}

int remove_element(linked_list **list, void *element) {

	if(*list) {
		if((*list)->data == element) {									// if the list's data is the element
			remove_first(list);														// calls remove_first with the list
			return 0;																			// go out of function when deletion have been made
		}
		return remove_element(&(*list)->next, element);	// calls the function again, with the same element and with the next block of [previous, data, next]
	}
	return -1;																				// if list is empty, simply return -1
}
