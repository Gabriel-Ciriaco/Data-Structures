#ifndef DYNAMIC-QUEUE_H
#define DYNAMIC-QUEUE_H

#include <stdbool.h>

typedef struct node
{
    int value;
    struct node * next;
} Node;

typedef struct dynamicQueue
{
    Node * bottom;
    Node * top;
} DynamicQueue;


Node * createNode(int value);

DynamicQueue createDynamicQueue();

bool isDQueueEmpty(DynamicQueue * dQueue);

void push(int value, DynamicQueue * dQueue);

int popLeft(DynamicQueue * dQueue);

void cleanDynamicQueue(DynamicQueue * dQueue);


#endif // DYNAMIC-QUEUE_H
