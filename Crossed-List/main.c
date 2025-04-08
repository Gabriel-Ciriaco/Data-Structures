#include "crossed-list.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{
    CrossedList cList = createCrossedList(20, 20);

    insertCElement(10, 0, 0, &cList);
    insertCElement(-5, 2, 1, &cList);


    printCrossedList(&cList);

    removeCElement(0, 0, &cList);

    insertCElement(16, 12, 9, &cList);

    printCrossedList(&cList);

    cleanCrossedList(&cList);

    return 0;
}
