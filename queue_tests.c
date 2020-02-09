//
// Created by Brian Button on 2/8/20.
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
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

void test_correct_result_returned_after_enqueue() {
   queue queue;
   initialize(&queue);

   enqueue(&queue, (void*)1);
   int result = (int)dequeue(&queue);

   assert(result == 1);

}

void test_multiple_enqueues_returned_in_correct_order() {
  queue queue;
  initialize(&queue);

  enqueue(&queue, (void*) 1);
  enqueue(&queue, (void*) 2);
  enqueue(&queue, (void*) 3);

  int r1 = (int)dequeue(&queue);
  int r2 = (int)dequeue(&queue);
  int r3 = (int)dequeue(&queue);

  assert(r1 == 1);
  assert(r2 == 2);
  assert(r3 == 3);
}

void run_queue_tests() {
    test_null_returned_when_queue_empty();
    test_is_empty_when_queue_empty();
    test_not_empty_after_enqueue();
	test_correct_result_returned_after_enqueue();
	test_multiple_enqueues_returned_in_correct_order();
}

