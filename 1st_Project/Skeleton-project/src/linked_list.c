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
	root->data = NULL;
	root->next = NULL;
	root->previous = NULL;
	return root;
}

void add_element(linked_list *list, void *element) {

	linked_list *newNode = init_linked_list();
	newNode->data = element;
	while(list->next) {
	 	list = list->next;
	}
	list->next = newNode;
	newNode->previous = list;
}
/*
	size_t is always the same size as a pointer
*/

// conflicting type af size_t og int (jeg har ændret det til type int begge
// steder)
// har kørt din kode i visualizer og kan se at din size aldrig bliver større
// end 1 på trods af flere elementer i listen
int linked_list_size(linked_list *list) {
	int i = 0;
	while (list) {
		i++;
		list = list->next;
	}
	return i;
}

/*
	Changed to double-pointer,
	to make the list NOT point to gibberish after removal.
	Simply easier to make a double pointer, than working with a single-pointer
	for this case.
*/

// du havde conflicting typer her.. dvs du har lavet list til dobbeltpointer her
// men single pointer i header-deklerationen, så har ændret headeren for dig
void *remove_first(linked_list **list) {

	void *data = (*list)->data;
	linked_list *old = *list;
	*list = old->next;
	(*list)->previous = old->previous;
	free(old);
	return data;
}

int remove_element(linked_list *list, void *element) {

	linked_list *old = NULL;	//To keep track of where we are
	while(list->next) {
		list = list->next;
		if(list->data == element) {
			remove_first(&list);
			list->previous = old;
			return 0;
		}
		old = list;	//
	}
	return -1;
}
