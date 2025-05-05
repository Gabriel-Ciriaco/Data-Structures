#include "static-hash-table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Node createNode(char * value)
{
    Node newNode;

    strcpy(newNode.value, value);

    newNode.nextNode = -1;

    return newNode;
}

StatichHashTable createHashTable()
{
    StatichHashTable newTable;

    for (int i = 0; i < MAX_HASH_TABLE; i++)
    {
        newTable.table[i] = createNode("");
    }

    return newTable;
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

int isPosEmpty(int pos, StatichHashTable * sHTable)
{
    return strcmp(sHTable->table[pos].value, "") == 0;
}

void insertValue(char * value, StatichHashTable * sHTable)
{
    int value_index = hash_function(value);

    Node elementFromPos = sHTable->table[value_index];

    if(isPosEmpty(value_index, sHTable))
    {
        sHTable->table[value_index] = createNode(value);
    }
    else
    {
        for (int i = value_index + 1; i < MAX_HASH_TABLE; i++)
        {
            if (isPosEmpty(i, sHTable))
            {
                sHTable->table[value_index].nextNode = i;
                sHTable->table[i] = createNode(value);
                break;
            }
        }
    }
}
