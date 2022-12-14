#include "task2.h"

int main(void) {
    ErrorCodes errorCode = noErrors;

    List* myList = createList(&errorCode);

    char* string1 = "aaabbbcc";
    char* string2 = "bbbcccaa";
    char* string3 = "cccaaabb";

    addAStrings(myList, &errorCode);

    addElement(myList, string1, &errorCode);

    addAStrings(myList, &errorCode);

    deleteList(myList, &errorCode);
}