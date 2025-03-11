#include "dynamic-string.h"

#include <stdio.h>
#include <stdlib.h>

struct dynamicString {
    char c;
    struct dynamicString * ant;
    struct dynamicString * prox;
};

int main()
{
    DynamicString * head = createString();

    printf("%d", stringLen(head));
    free(head);

    return 0;
}
