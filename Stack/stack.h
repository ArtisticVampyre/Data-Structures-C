//
// Created by Sergiu on 19/05/2021.
//

#ifndef OPENPROJECTS_STACK_H
#define OPENPROJECTS_STACK_H

#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "Shared/Structures/node.h"
#include "Shared/Actions/display.h"

typedef struct stack {
    int size;
    struct node *head;
    struct node *tail;
} stack;

stack *create_stack(int data_param, int stack_size) {
    stack *new_stack = (stack *) malloc(sizeof(stack));
    new_stack->head = create_node(data_param, NULL, NULL);
    new_stack->tail = new_stack->head;
    new_stack->size = stack_size;
    return new_stack;
}

bool is_full(stack *root) {
    if (root->tail->index == root->size-1) {
        return true;
    }
    return false;
}

void push_stack(stack *root, int data_param) {
    if (is_full(root) == false) {
        node *new_element = create_node(data_param, root->tail, NULL);
        root->tail->next = new_element;
        root->tail = new_element;
    } else {
        warn("Stack Size exceded\n");
    }
}

void pop_stack(stack *root) {
    node *element = root->head;
    while (element->next != root->tail) {
        element = element->next;
    }
    element->next = NULL;
    free(root->tail);
    root->tail = element;
}

node *get(stack *root) {
    return root->tail;
}

void print_stack(stack *root) {
    node *current_element = root->head;
    printf("\n===================================================================\n");
    while (current_element) {
        printf("[%d] : %d\n", current_element->index, current_element->data);
        current_element = current_element->next;
    }
    printf("===================================================================\n");
}


#endif //OPENPROJECTS_STACK_H
