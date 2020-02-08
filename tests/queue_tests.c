//
// Created by Brian Button on 2/8/20.
//

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct queue_node {
    struct queue_node * next;
    struct queue_node * previous;
    void * value;
} queue_node;

typedef struct queue {
    queue_node * head;
    queue_node * tail;
} queue;

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

void test_null_returned_when_queue_empty() {
    queue queue;
    initialize(&queue);

    void * object = dequeue(&queue);

    assert(object == NULL);
}

void test_is_empty_when_queue_empty() {
    queue queue;
    initialize(&queue);

    assert(empty(&queue));
}

void test_not_empty_after_enqueue() {
    queue queue;
    initialize(&queue);

    enqueue(&queue, (void *)"hello");

    assert(!empty(&queue));
}



//void test_non_null_returned_after_single_push() {
//    queue queue;
//    initialize(&queue);
//
//    enqueue((void*)1);
//
//}

int main(int argc, char ** argv) {
    test_null_returned_when_queue_empty();
    test_is_empty_when_queue_empty();
    test_not_empty_after_enqueue();
}

