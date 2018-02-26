#include "graph.h"

void cycle_detection(graph *g) {

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

  linked_list *LIST = init_linked_list();

  linked_list *SET = init_linked_list();

  while(SET != 0) {
    remove_first(&SET);
    //add_element();
  }

}
