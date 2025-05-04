#include "dynamic-queue.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    DynamicQueue dQueue = createDynamicQueue();

    push(1, &dQueue);
    push(2, &dQueue);
    push(3, &dQueue);
    push(4, &dQueue);
    push(5, &dQueue);

    printf("\nBottom: %d\nTop: %d\n\n",
            dQueue.bottom->value,
            dQueue.top->value);

    printf("\nPopped element: %d\n", popLeft(&dQueue));
    printf("\nBottom: %d\nTop: %d\n\n",
            dQueue.bottom->value,
            dQueue.top->value);

    printf("\nPopped element: %d\n", popLeft(&dQueue));
    printf("\nBottom: %d\nTop: %d\n\n",
            dQueue.bottom->value,
            dQueue.top->value);

    printf("\nPopped element: %d\n", popLeft(&dQueue));
    printf("\nBottom: %d\nTop: %d\n\n",
            dQueue.bottom->value,
            dQueue.top->value);

    printf("\nPopped element: %d\n", popLeft(&dQueue));
    printf("\nBottom: %d\nTop: %d\n\n",
            dQueue.bottom->value,
            dQueue.top->value);

    printf("\nPopped element: %d\n", popLeft(&dQueue));
    printf("\nBottom: %d\nTop: %d\n\n",
            dQueue.bottom,
            dQueue.top);

    cleanDynamicQueue(&dQueue);

    return 0;
}
