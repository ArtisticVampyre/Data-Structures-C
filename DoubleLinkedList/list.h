//
//
#ifndef OPENPROJECTS_LIST_H
#define OPENPROJECTS_LIST_H

#include <stdio.h>
#include "stdlib.h"
#include "Shared/Structures/node.h"

typedef struct dll {
    struct node *head;
    struct node *tail;
} dll;

dll *create_dll(int data_param) {
    dll *new_list = (dll *) malloc(sizeof(dll));
    new_list->head = create_node(data_param, NULL, NULL);
    new_list->tail = new_list->head;
    return new_list;
}

#endif //OPENPROJECTS_LIST_H
