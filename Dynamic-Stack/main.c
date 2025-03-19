#include "dynamic-stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    DynamicStack dStack = createDynamicStack();

    push(1, &dStack);
    push(2, &dStack);
    push(3, &dStack);
    push(4, &dStack);

    printf("\nStack is empty: %s\n", isStackEmpty(&dStack) ? "true" : "false");

    int a = pop(&dStack);
    int b = pop(&dStack);
    int c = pop(&dStack);
    int d = pop(&dStack);

    printf("\nStack is empty: %s\n", isStackEmpty(&dStack) ? "true" : "false");

    printf("\n%d %d %d %d\n", a, b, c, d);

    cleanStack(&dStack);

    return 0;
}
