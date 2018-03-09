
For the following project, a graph using Kahn's Algorithm had to be solved, using a doubly linked list.
The graphs provided are given as followed:

5
01000
00010
00000
00100
10100

The ways of using the doubly linked list were analyzed:
- adding an element on the tail of the linked list
- removing the first and/or whichever desired element

When adding an element to a linked list, one must iterate through the entire list, and add it at the very end.
Using pointers, provided a method of working around that:
Making a 'newNode' that stores the given element in the data, then, if there's still a next element,
the list will point to its next, until end of the list (aka: its 'next' would point at NULL).
When it have come to an end, 'newNode' will place itself on the 'next' spot, aswell as making where the list currently is located, its 'previous'.

--------------------------------------------------------------------------------

Deleting an element from a doubly linked list have to be done as shown below, the pointers will have to be rearranged, so they point to the correct blocks.

        +--------------------+ -> +--------------------+ -> +--------------------+
NULL <- | prev | data | next |    | prev | data | next |    | prev | data | next | -> NULL
        +--------------------+ <- +--------------------+ <- +--------------------+

When deleting an element from the linked_list, the pointers need to be updated:

        +--------------------+       +--------------------+       +--------------------+
NULL <- | prev | data | next |       | prev | data | next |       | prev | data | next | -> NULL
        +--------------------+       +--------------------+       +--------------------+
                  ^          |                                    ^   |
                  |          |____________________________________|   |
                  |___________________________________________________|

Then the data can be free'd:

        +--------------------+ -> +--------------------+
NULL <- | prev | data | next |    | prev | data | next | -> NULL
        +--------------------+ <- +--------------------+

This was done by first checking if there were an actual list, just for safety.
Then an 'old' pointer for moving through the list was created, then do as above, whatever you wish to delete, needs to not have something pointed to it.

--------------------------------------------------------------------------------

A way to visualize the graph was required:

- getline was used to read the first line, which was used as a size in a nested for-loop, that was used to read the graph as a two-dimensional array.
- For each iteration, if the element had any 'out_neighbours', its 'edge' would be deleted, same with the element it pointed towards' 'in_neighbours'.

--------------------------------------------------------------------------------

The function 'int remove_element(linked_list **list, void *element)' in the 'linked_list' header file have been changed to a double-pointer,
to ensure that the element won't point towards an invalid address, after a deletion.
