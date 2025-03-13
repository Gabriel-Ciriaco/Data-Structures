#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

typedef struct node {
    char c;

    struct node * prev;
    struct node * next;
} Node;

typedef struct dynamicString
{
    Node * head;
    Node * tail;

    int length;
} DynamicString;


Node * createNode(char c);

DynamicString createString();

void cleanString(DynamicString * strDim);

void printString(DynamicString * strDim);

int stringLen(DynamicString * strDim);

void insertChar(char c, DynamicString * strDim);

void copyString(DynamicString * output, DynamicString * input);

void concatString(DynamicString * str3, DynamicString * str2, DynamicString * str1);

void removeChars(DynamicString * strDim, int start, int nro);

#endif // DYNAMIC-STRING_H
