Simon D. Jørgensen






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





Fuck space.
