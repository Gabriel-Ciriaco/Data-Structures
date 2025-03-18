#ifndef DYNAMIC-STACK_H
#define DYNAMIC-STACK_H


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

void createDynamicStack();

void push(int value, DynamicStack * dStack);

int pop(DynamicStack * dStack);

void cleanStack(DynamicStack * dStack);

#endif // DYNAMIC-STACK_H
