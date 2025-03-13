#include "dynamic-string.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{
    DynamicString strDim = createString();
    DynamicString strDim2 = createString();

    insertChar('g', &strDim);
    insertChar('a', &strDim);
    insertChar('b', &strDim);
    insertChar('r', &strDim);
    insertChar('i', &strDim);
    insertChar('e', &strDim);
    insertChar('l', &strDim);

    printString(&strDim);

    copyString(&strDim2, &strDim);

    cleanString(&strDim);
    cleanString(&strDim2);

    return 0;
}
