//
// Created by Brian Button on 2/8/20.
//

#include <assert.h>
#include <stdlib.h>
#include "queue.h"

void test_null_returned_when_queue_empty() {
    struct queue queue;
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

void run_queue_tests() {
    test_null_returned_when_queue_empty();
    test_is_empty_when_queue_empty();
    test_not_empty_after_enqueue();
}

