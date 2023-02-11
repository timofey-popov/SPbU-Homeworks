#include "mergeSort.h"
#include "../linkedList/linkedList.h"

int main(void) {
    ListErrors errorCode = noErrorsInList;

    List* initList = createList;
    addElement(3, initList, &errorCode);
    addElement(1, initList, &errorCode);
    addElement(2, initList, &errorCode);
    addElement(4, initList, &errorCode);

    List* result = mergeSort(initList, &errorCode);

    printList(result, &errorCode);

    return 0;
}