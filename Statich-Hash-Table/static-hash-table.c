#include "static-hash-table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash_function(char * value)
{
    int key = 0;

    for (int i = 0; i < strlen(value); i++)
    {
        key += ((i+1) * value[i]) % PRIME_NUMBER;
    }

    return key % MAX_HASH_TABLE;
}

