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

vertex *scan(graph *g) {

  for(size_t i = 0; i < g->number_vertices; i++){
    vertex *ptr = g->vertices + i;                              // creates a pointer that iterates over all vertices
    if(ptr->out_neighbours && !ptr->in_neighbours) return ptr;  // if the pointer have out_neighbours and no in_neighbours, return the pointer
  }
  return NULL;                                                  // returns NULL if the for-loop can't return a valid pointer
}

void cycle_detection(graph *g) {

  char *bookkeep = calloc(g->number_vertices, sizeof(char));    // checks for whenever something is added to the list 'L'
  linked_list *L = NULL;
  vertex *n;
  while( (n = scan(g)) ) {
    if(L) {
      add_element(L, n);
    } else {
      L = init_linked_list();
      L->data = n;
    }
    bookkeep[n->id] = 1;                                        // marks location as "visited"
    vertex *m;
    while( (m = remove_first(&n->out_neighbours)) ) {
      remove_element(&m->in_neighbours, n);
    }
  }
  for(size_t i = 0; i < g->number_vertices; i++) {
    if(g->vertices[i].in_neighbours) {
      printf("CYCLE DETECTED!\n");
      goto Free;                                               // goes to the 'Free' label
    } else if (!bookkeep[i]) {
      add_element(L, g->vertices + i);
    }
  }
  vertex *v;
  linked_list *l = L;
  while(l && ( v = l->data ) ) {
    printf("%d%s", v->id, l->next ? ", " : "\n" );
    l = l->next;
  }

  Free: {
    free(bookkeep);
  }
}
