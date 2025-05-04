#ifndef STATIC-HASH-TABLE_H
#define STATIC-HASH-TABLE_H

#define MAX_HASH_TABLE 100
#define PRIME_NUMBER 97

typedef struct staticHashTable
{
    char * table[MAX_HASH_TABLE];

} StatichHashTable;

int hash_function(char * value);

void insertValue(int key);

void removevalue(int key);

void getValue(int key);

#endif // STATIC-HASH-TABLE_H
