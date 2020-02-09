//
// Created by Brian Button on 2/8/20.
//

#ifndef BFS_QUEUE_H
#define BFS_QUEUE_H

typedef struct queue_node queue_node;

typedef struct queue {
    queue_node * head;
    queue_node * tail;
} queue;

extern void initialize(queue * queue);
extern int empty(queue * queue);
extern void * dequeue(queue * queue);
extern void enqueue(queue * queue, void * arg);

#endif //BFS_QUEUE_H
