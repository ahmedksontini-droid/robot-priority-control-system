#ifndef QUEUE_H
#define QUEUE_H

#include "command.h"

typedef struct Node {
    Command cmd;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void init_queue(Queue *q);
void enqueue(Queue *q, Command cmd);
Command dequeue(Queue *q);
int is_empty(Queue *q);

#endif
