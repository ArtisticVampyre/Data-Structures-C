#include <stdio.h>

#include "DoubleLinkedList/list.h"
#include "Stack/stack.h"
#include "Queue/queue.h"

void DoubleLinkedListTest(){

}

void QueueTest(){
    printf("Queue\n");
    queue *my_new_queue = initialize_queue(10);
    enqueue(my_new_queue,15);
    printf("%d\n",(int)dequeue(my_new_queue));
    printf("%d",(int)dequeue(my_new_queue));
}

void StackTest(){
    printf("Stack\n");
    stack *my_new_stack = create_stack(25,3);
    push_stack(my_new_stack,50);
    push_stack(my_new_stack,75);
    push_stack(my_new_stack,100);
    push_stack(my_new_stack,125);
    push_stack(my_new_stack,150);
    pop_stack(my_new_stack);
    node* last_element = get(my_new_stack);
    printf("Last Element : %d",last_element->data);
    print_stack(my_new_stack);
}

int main() {
    QueueTest();
    return 0;
}
