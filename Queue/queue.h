#include<stdbool.h>

#include "Shared/Structures/node.h"
#include "../Shared/Structures/node.h"

typedef struct queue {
    node *front;
    node *end;
    int size;
    int max;
} queue;

queue *initialize_queue(int initial_value, int max) {
    queue *q = (queue *) malloc(sizeof(struct queue));
    node *init_node = create_node(initial_value, NULL, NULL);
    init_node->priority = 0;
    q->front = q->end = init_node;
    q->size = 1;
    q->max = max;
    return q;
}

bool is_queue_full(queue *q) {
    if (q->end->index == q->max) {
        return true;
    }

    return false;
}

bool is_queue_empty(queue *q) {
    if (q->end->index == q->front->index) {
        return true;
    }

    return false;
}

bool enqueue(queue *q, int value) {
    if (is_queue_full(q)) {
        return false;
    }
    if(q->size > 1){
        q->end = create_node(value, q->end->previous, NULL,0);
    }else{
        q->end = create_node(value, q->front, NULL,0);
    }
    return true;
}

bool enqueue_with_priority(queue *q, int value,int priority) {
    if (is_queue_full(q)) {
        return false;
    }
    if(q->size > 1){
        q->end = create_node(value, q->end->previous, NULL,priority);
    }else{
        q->end = create_node(value, q->front, NULL,priority);
    }
    return true;
}

bool dequeue_highest_priority(queue *q) {
    if (is_queue_empty(q))
        return NULL;
    node *to_return = q->front;
    node *temp = q->front;
    while(temp){
        if(temp->priority > to_return->priority)
            to_return = temp;
        temp = temp->next;
    }
    free(temp);
    return (int*)to_return->data;
}

int *peek(queue *q) {
    if (is_queue_empty(q))
        return NULL;
    node *to_return = q->front;
    node *temp = q->front;
    while(temp){
        if(temp->priority > to_return->priority)
            to_return = temp;
        temp = temp->next;
    }
    free(temp);
    return (int*)to_return->data;
}

int *dequeue(queue *q) {
    if (is_queue_empty(q))
        return NULL;
    int *saved = (int *) q->front->data;
    node *temp = q->front;
    q->front->next->previous = NULL;
    q->front = q->front->next;
    free(temp);
    return saved;
}