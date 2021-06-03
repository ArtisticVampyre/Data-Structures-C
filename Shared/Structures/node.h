//
// Created by Sergiu on 19/05/2021.
//

#ifndef OPENPROJECTS_NODE_H
#define OPENPROJECTS_NODE_H

typedef struct node {
    int data;
    int index;
    struct node *previous;
    struct node *next;
} node;

node *create_node(int data_param, node *previous, node *next) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data_param;
    new_node->next = next;
    if (previous) {
        new_node->index = previous->index + 1;
    } else {
        new_node->index = 0;
    }
    return new_node;
}

#endif //OPENPROJECTS_NODE_H
