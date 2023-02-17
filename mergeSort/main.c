#include "mergeSort.h"

#include <stdio.h>

int main(void) {
    ListErrors errorCode = noErrorsInList;

    List* initialList = createList(&errorCode);
    addElement(0, initialList, &errorCode);
    addElement(-96, initialList, &errorCode);
    addElement(-150, initialList, &errorCode);
    addElement(46, initialList, &errorCode);
    addElement(-3, initialList, &errorCode);
    addElement(95, initialList, &errorCode);
    addElement(3, initialList, &errorCode);
    addElement(-96, initialList, &errorCode);

    List* result = mergeSort(initialList, &errorCode);

    printf("Here's the sorted list:\n");
    printList(result, &errorCode);

    deleteList(initialList, &errorCode);
    deleteList(result, &errorCode);
    if (errorCode) {
        printf("An error occured: %d", errorCode);
        return errorCode;
    }

    return 0;
}
