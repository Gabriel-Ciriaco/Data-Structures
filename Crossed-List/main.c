#include "crossed-list.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{
    CrossedList cList = createCrossedList(20, 20);

    insertCElement(1, 0, 1, &cList);
    insertCElement(2, 0, 0, &cList);
    insertCElement(3, 0, 2, &cList);
    insertCElement(4, 1, 1, &cList);
    insertCElement(5, 8, 4, &cList);
    insertCElement(6, 3, 9, &cList);



    printCrossedList(&cList);

    removeCElement(0, 0, &cList);

    printCrossedList(&cList);

    cleanCrossedList(&cList);

    return 0;
}
