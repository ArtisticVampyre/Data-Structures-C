//
// Created by Sergiu on 19/05/2021.
//

#ifndef OPENPROJECTS_NODE_H
#define OPENPROJECTS_NODE_H

typedef struct node {
    int data;
    int index;
    int priority;
    struct node *previous;
    struct node *next;
} node;

node *create_node(int data_param, node *previous, node *next, int priority) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data_param;
    new_node->next = next;
    if (previous) {
        new_node->index = previous->index + 1;
        previous->next = new_node;
    } else {
        new_node->index = 0;
    }
    if (priority)
        new_node->priority = priority;

    return new_node;
}

void *remove_node(node* main_node){
    main_node->previous->next = main_node->next;
    main_node->next->previous = main_node->previous;
    free(main_node);
}

#endif //OPENPROJECTS_NODE_H
