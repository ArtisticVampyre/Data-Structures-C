#include<stdbool.h>

typedef struct queue{
    int *content;
    int front, end;
    int max;
}queue;

queue * initialize_queue(int max)
{
    queue* q =  (queue*)malloc(sizeof(struct queue));
    q->content = (int*)malloc(sizeof(int)* max);
    q->front = q->end = 0;
    q->max = max;

    return q;
}

bool is_queue_full(queue *q)
{
    if (q->end == q->max)
    {
        return true;
    }

    return false;
}

bool is_queue_empty(queue *q)
{
    if (q->end == q->front)
    {
        return true;
    }

    return false;
}

bool enqueue(queue *q, int value)
{
    if(is_queue_full(q))
    {
        return false;
    }

    q->content[q->end] = value;
    q->end++;

    return true;
}

int* dequeue(queue *q)
{
    if(is_queue_empty(q))
    {
        return NULL;
    }

    int* saved = (int *) q->content[q->front];
    q->front++;

    return saved;
}