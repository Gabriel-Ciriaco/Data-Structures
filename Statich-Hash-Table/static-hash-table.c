#include "static-hash-table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

StatichHashTable createHashTable()
{
    StatichHashTable newTable;

    for (int i = 0; i < MAX_HASH_TABLE; i++)
    {
        newTable.table[i] = NULL;
    }

    return newTable;
}

Node createNode(char * value)
{
    Node newNode;

    strcpy(newNode.value, value);

    newNode.value = -1;

    return newNode;
}

int hash_function(char * key)
{
    int sum = 0;

    for (int i = 0; i < strlen(key); i++)
    {
        sum += (i * key[i]) % PRIME_NUMBER;
    }

    return sum % MAX_HASH_TABLE;
}

void insertValue(char * value, StatichHashTable * sHTable)
{
    int value_index = hash_function(value);

    if(!sHTable->table[value_index])
    {
        sHTable->table[value_index] = createNode(value);
    }
    else
    {
        for (int i = value_index + 1; i < MAX_HASH_TABLE; i++)
        {
            if (!sHTable->table[i])
            {
                sHTable->table[value_index].nextNode = i;
                sHTable->table[i] = createNode(value);
                break;
            }
        }
    }
}
