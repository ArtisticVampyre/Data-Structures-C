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
    int size;
} dll;

dll *create_dll(int data_param) {
    dll *new_list = (dll *) malloc(sizeof(dll));
    new_list->head = create_node(data_param, NULL, NULL,0);
    new_list->tail = new_list->head;
    new_list->size = 1;
    return new_list;
}

void insert_front_ldi(dll* root,int data_param){
    node* temp = root->head;
    root->head = create_node(data_param,NULL,temp,0);
    root->size +=1;
}

void insert_end_ldi(dll* root,int data_param){
    node* temp = root->tail;
    root->tail = create_node(data_param,temp,NULL,0);
    root->size +=1;
}

void remove_front_ldi(dll* root){
    remove_node(root->head);
}

void remove_last_ldi(dll* root){
    remove_node(root->tail);
}

#endif //OPENPROJECTS_LIST_H
