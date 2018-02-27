#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/*
For cycle detection, you should use Kahn’s algorithm,
which generates a topological sort in time O(|V|+|E|).
A topological sort is only possible if the graph does not have any cycles.

L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
while S is non-empty do
  remove a node n from S
  add n to tail of L
  for each node m with an edge e from n to m do
    remove edge e from the graph
    if m has no other incoming edges, then
      insert m into S
if graph has edges then
  return error (graph has at least one cycle)
else
  return L (a topologically sorted order)
*/

vertex *scan(graph * g){
  for(size_t i = 0; i < g->number_vertices; i++){
    vertex *ptr = g->vertices + i;                              // creates a pointer that iterates over all vertices
    if(ptr->out_neighbours && !ptr->in_neighbours) return ptr;  // if the pointer have out_neighbours and no in_neighbours, return the pointer
  }
  return NULL;                                                  // returns NULL if the for-loop can't return a valid pointer
}

void cycle_detection(graph *g) {
  // create a char-pointer checkmark
  char *checkmark = calloc(g->number_vertices, sizeof(*checkmark));
  linked_list *L = init_linked_list();  // L ← Empty list that will contain the sorted elements
  vertex *n = scan(g);                              //
  while(n) {
    printf("n is TRUE\n");
    if(L) {
      add_element(L, n);                            // add element n to the list 'L'
    } else {
      L = init_linked_list();                       // initiates the list 'L'
      L->data = n;                                  // list 'L's data will now contain element n
    }
    printf("%d, ", n->id);                          //
    checkmark[n->id] = 1;                           //
    vertex *m = remove_first(&(n->out_neighbours)); //
    while (m) {
      remove_element(&(n->in_neighbours), m);       //
      m = remove_first(&(n->out_neighbours));       //
    }
    n = scan(g);                                    //
  }
  printf("\n");
  for(size_t i = 0; i < g->number_vertices; i++) {
    printf("%lu, %d, %i\n", i, (int)checkmark[i], !g->vertices[i].in_neighbours);
    if(!checkmark[i] && !g->vertices[i].in_neighbours) {
      add_element(L, g->vertices + i);              //
      checkmark[i] = 1;                             //
    }
  }

  //Kahn's algorithm is now done and we can now check for nodes which have been unaccounted for.
  for(size_t i = 0; i < g->number_vertices; i++) {
    if(!checkmark[i]) {                             //
      printf("CYCLE DETECTED!\n");
      free(checkmark);                              // frees checkmark from memory
      return;
    }
  }

  free(checkmark);                                  // frees checkmark from the heap
  linked_list *l = L;                               //
  while ( l ) {
    printf("%d%s", ((vertex*)l->data)->id ,l->next ? ", " : "\n" ); // prints the list
    l = l->next;
  }
}
