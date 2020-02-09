//
// Created by Brian Button on 2/8/20.
//

#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

typedef struct queue_node {
    struct queue_node * next;
    struct queue_node * previous;
    void * value;
} queue_node;


void initialize(queue * queue) {
    queue->head = queue->tail = NULL;
}

int empty(queue * queue) {
    return queue->head == NULL;
}

void * dequeue(queue * queue) {
    if(queue->head == NULL) return NULL;

    queue_node * tail = queue->tail;
    void * tail_value = tail->value;

    if(queue->tail == queue->head)
        initialize(queue);
    else
        queue->tail = queue->tail->previous;

    free(tail);

    return tail_value;
}

void enqueue(queue * queue, void * arg) {
    queue_node * new_node = (queue_node *)malloc(sizeof(queue_node));
    new_node->value = arg;

    if(empty(queue)) {
        queue->head = queue->tail = new_node;
        new_node->previous = NULL;
        new_node->next = NULL;
    } else {
        queue->tail->next = new_node;
        new_node->next = NULL;
        new_node->previous = queue->tail;
        queue->tail = new_node;
    }
}

