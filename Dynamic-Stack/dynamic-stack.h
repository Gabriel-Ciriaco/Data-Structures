#ifndef DYNAMIC-STACK_H
#define DYNAMIC-STACK_H

#include <stdbool.h>

typedef struct node
{
    int value;
    struct node * next;
} Node;

typedef struct dynamicStack
{
    Node * top;
} DynamicStack;


Node * createNode(int value);

DynamicStack createDynamicStack();

bool isStackEmpty(DynamicStack * dStack);

void push(int value, DynamicStack * dStack);

int pop(DynamicStack * dStack);

void cleanStack(DynamicStack * dStack);

#endif // DYNAMIC-STACK_H
