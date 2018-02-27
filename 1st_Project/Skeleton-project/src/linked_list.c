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

	linked_list *newNode = init_linked_list();	// initializes with a 'newNode'
	newNode->data = element;										// element given in argument goes to the data slot
	while(list->next) {													// while there's a next element present:
	 	list = list->next;												// list points to its next and sets itself there
	} list->next = newNode;											// sets the next-pointer from where list currently is, to the 'newNode'
	newNode->previous = list;										// sets the previous-pointer from 'newNode' to its previous
}

size_t linked_list_size(linked_list *list) {
	size_t i = 0;																	// counter for size
	while (list->next) {
		i++;																			// increments the size
		list = list->next;												// list is now placed at the next position
	}
	return i;																		// returns the size
}

/*
because our first node is a 'control'-node without data,
we want to ensure this node wont be deleted.
Instead we delete what it points to (the real first node) then we return its data.
*/
// void *remove_first(linked_list **list) {
//     if((*list)->next->next){                		 	// if linked_list has more than one node
//       void *data = (*list)->next->data;
//       linked_list *old = *list;
//       linked_list *toBeDeleted = old->next;
//       old->next->next->previous = (*list);
//       old->next = old->next->next;
//       free(toBeDeleted);													// frees from memory, avoiding memory leaks
//       return data;
// 		} else {                          		  			// if linked_list has only one node
//         void *data = (*list)->next->data;
//         linked_list *toBeDeleted = (*list)->next;
//         (*list)->next = NULL;
//         free(toBeDeleted);
//         return data;
//       }
// }

void *remove_first(linked_list **list) {
	if(!*list) return NULL;												// if list is empty, return NULL
	linked_list *old = *list;											// creates a pointer, to maintain the other pointer 'list'
	void *data = old->data;												// the data is
	*list = old->next;														// 'list' is now pointing towards the 'old' pointers' next
	if (*list) (*list)->previous = old->previous;	// makes the 'list' pointer, now have its previous pointer to point towards NULL, instead of inaccessible memory
	free(old);																		// frees up old, since the pointers have now been updated
	return data;

}

int remove_element(linked_list **list, void *element) {
	/*linked_list **ptr =
	linked_list *old = NULL;				//To keep track of where we are
	while(list->next) {
		//list = list->next;						// list is set to its next
		if(list->data == element) {		// if the wanted element is at location, jump into the if-statement
			remove_first(&list);				// calls the remove_first with the dereferenced list
			list->previous = old;				//
			return 0;
		}
		old = list;										//
	}
	return -1;*/

	if(*list) {
		if((*list)->data == element){
			remove_first(list);														// calls remove_first with the list when the element is located
			return 0;
		}
		return remove_element(&(*list)->next, element);	// calls the function again, with the same element and with the next block of [previous, data, next]
	}
	return -1;																				// if list is empty, simply return -1
}
