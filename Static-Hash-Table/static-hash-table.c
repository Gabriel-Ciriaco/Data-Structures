#include "static-hash-table.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


Node createNode(char * key, char * value)
{
    Node newNode;

    strcpy(newNode.key, key);
    strcpy(newNode.value, value);

    newNode.nextNode = TERMINAL_NODE;

    return newNode;
}

StatichHashTable createHashTable()
{
    StatichHashTable newTable;

    for (int i = 0; i < MAX_HASH_TABLE; i++)
    {
        newTable.table[i] = createNode(NULL_VALUE, NULL_VALUE);
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

bool isPosEmpty(int pos, StatichHashTable * sHTable)
{
    return strcmp(sHTable->table[pos].key, NULL_VALUE) == 0;
}

void insertValue(char * key, char * value, StatichHashTable * sHTable)
{
    int index = hash_function(key);

    if (!isPosEmpty(index, sHTable))
    {
        int curIndex = index;
        int nextIndex = sHTable->table[curIndex].nextNode;

        while (nextIndex != TERMINAL_NODE)
        {
            curIndex = nextIndex;
            nextIndex = sHTable->table[nextIndex].nextNode;
        }

        for (int i = curIndex; i < MAX_HASH_TABLE; i++)
        {
            if (isPosEmpty(i, sHTable))
            {
                sHTable->table[curIndex].nextNode = i;

                sHTable->table[i] = createNode(key, value);

                return;
            }
        }
    }
    else
    {
        sHTable->table[index] = createNode(key, value);
    }
}

void removeValue(char * key, char * value, StatichHashTable * sHTable)
{

}
