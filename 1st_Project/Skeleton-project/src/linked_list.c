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

	linked_list *newNode = init_linked_list();	// initializes with a 'newNode'
	newNode->data = element;										// element given in argument goes to the data slot
	while(list->next) {													// while there's a next element present:
	 	list = list->next;												// list points to its next and sets itself there
	} list->next = newNode;											// sets the next-pointer from where list currently is, to the 'newNode'
	newNode->previous = list;										// sets the previous-pointer from 'newNode' to its previous
}

int linked_list_size(linked_list *list) {
	int i = 0;																	// counter for size
	while (list->next) {												//
		i++;																			//
		list = list->next;												//
	}
	return i;																		// returns the size
}

/*
because our first node is a 'control'-node without data,
we want to ensure this node wont be deleted.
Instead we delete what it points to (the real first node) then we return its data.
*/
void *remove_first(linked_list **list) {
    if((*list)->next->next){                 	// if linked list has more than one node
      void *data = (*list)->next->data;
      linked_list *old = *list;
      linked_list *toBeDeleted = old->next;
      old->next->next->previous = (*list);
      old->next = old->next->next;
      free(toBeDeleted);
      return data;
      } else {                            		// if linked list has only one node
        void *data = (*list)->next->data;
        linked_list *toBeDeleted = (*list)->next;
        (*list)->next = NULL;
        free(toBeDeleted);
        return data;
      }
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
