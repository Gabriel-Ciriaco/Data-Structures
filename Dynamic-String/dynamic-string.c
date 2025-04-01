#include "dynamic-string.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


Node * createNode(char c)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->c = c;

    newNode->prev = NULL;
    newNode->next = NULL;
}

DynamicString createString()
{
    DynamicString strDim;

    strDim.head = NULL;
    strDim.tail = NULL;

    strDim.length = 0;

    return strDim;
}

void cleanString(DynamicString * strDim)
{
    if (!strDim->head) return;

    Node * cur = strDim->head;

    while (cur->next)
    {
        if (cur->prev)
        {
            free(cur->prev);
            cur->prev = NULL;
        }

        cur = cur->next;
    }

    free(cur);
    cur = NULL;
}

void printString(DynamicString * strDim)
{
    if (!strDim->head) return;

    Node * cur = strDim->head;

    while (cur)
    {
        printf("%c", cur->c);

        cur = cur->next;
    }

}

int stringLen(DynamicString * strDim)
{
    return strDim->length;
}

void insertChar(char c, DynamicString * strDim)
{
    Node * newNode = createNode(c);

    if (!strDim->head)
    {
        strDim->head = newNode;
        strDim->tail = newNode;
    }
    else
    {
        newNode->prev = strDim->tail;

        (strDim->tail)->next = newNode;

        strDim->tail = newNode;
    }

    strDim->length++;
}

void copyString(DynamicString * output, DynamicString * input)
{
    Node * cur = input->head;
    Node * out = output->head;

    while (cur && out)
    {
        out->c = cur->c;

        cur = cur->next;
        out = out->next;
    }

    while (cur)
    {
        insertChar(cur->c, output);

        cur = cur->next;
    }

}

void concatString(DynamicString * str3,
                  DynamicString * str2,
                  DynamicString * str1)
{
    copyString(str3, str1);

    Node * concat = str2->head;

    while(concat)
    {
        insertChar(concat->c, str3);

        concat = concat->next;
    }
}

void removeChars(DynamicString * strDim, int start, int nro)
{
    Node * cur = strDim->head;
    Node * nodeToRemove = NULL;

    int pos = 0;

    while (cur)
    {
        if (pos >= start &&
            pos < (start + nro))
        {
            nodeToRemove = cur;

            if (nodeToRemove->prev)
            {
                (nodeToRemove->prev)->next = nodeToRemove->next;
            }

            if (nodeToRemove->next)
            {
                (nodeToRemove->next)->prev = nodeToRemove->prev;
            }


            if (nodeToRemove == strDim->head)
            {
                strDim->head = nodeToRemove->next;
            }

            if(nodeToRemove == strDim->tail)
            {
                strDim->tail = nodeToRemove->prev;
            }
        }

        cur = cur->next;

        if(nodeToRemove)
        {
            free(nodeToRemove);

            // Prevent acess to deleted space.
            nodeToRemove = NULL;

            strDim->length--;
        }

        pos++;
    }
}

void insertSubstring(DynamicString * strDim, DynamicString * substring, int start)
{
    Node * cur = strDim->head;
    Node * subCur = substring->head;

    Node * newNode = NULL;

    int pos = 0;

    while (cur && subCur)
    {
        while (pos >= start && subCur)
        {
            newNode = createNode(subCur->c);

            if (cur == strDim->head)
            {
                strDim->head = newNode;
            }

            if (cur->prev)
            {
                (cur->prev)->next = newNode;
            }

            newNode->prev = cur->prev;
            newNode->next = cur;

            cur->prev = newNode;

            subCur = subCur->next;
        }

        cur = cur->next;
        pos++;
    }

    // Insert the remaining chars.
    while (subCur)
    {
        insertChar(subCur->c, strDim);
        subCur = subCur->next;
    }
}

bool strIsLess(DynamicString * str1, DynamicString * str2)
{
    return (str1->length < str2->length);
}

bool strIsEqual(DynamicString * str1, DynamicString * str2)
{
    if (str1->length != str2->length) return false;

    Node * node1 = str1->head;
    Node * node2 = str2->head;

    while (node1 && node2)
    {
        if (node1->c != node2->c) return false;

        node1 = node1->next;
        node2 = node2->next;
    }

    return true;
}

int searchString(DynamicString * strDim, DynamicString * searchStr)
{
	const int NOT_FOUND = -1;

	int local = 0;

	if (!strIsLess(searchStr, strDim) &&
        !strIsEqual(searchStr, strDim)) return NOT_FOUND;

	Node * cur = strDim->head;
	Node * subCur = searchStr->head;

	int equalChars = 0;

	while (cur && subCur)
	{
		if (cur->c == subCur->c)
		{
			equalChars++;
			subCur = subCur->next;
		}
		else if (equalChars > 0 && equalChars != stringLen(searchStr))
		{
			equalChars = 0;
			subCur = searchStr->head;
		}
		else if (equalChars == stringLen(searchStr))
		{
			// Retorna a posição de inicio da substring.
			return local - stringLen(searchStr);
		}

		cur = cur->next;
		local++;
	}

	return (equalChars == stringLen(searchStr)) ? local - stringLen(searchStr) : NOT_FOUND;
}
