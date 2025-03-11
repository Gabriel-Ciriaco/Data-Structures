#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

typedef struct dynamicString DynamicString;


DynamicString * createString();

void cleanString(DynamicString * strDim);

void printString(DynamicString * strDim);

int stringLen(DynamicString * strDim);

void insertChar(char c, DynamicString * strDim);

void copyString(DynamicString * output, DynamicString * input);

#endif // DYNAMIC-STRING_H
