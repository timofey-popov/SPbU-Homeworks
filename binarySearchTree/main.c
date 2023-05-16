#include "binarySearchTree.h"

#include <stdio.h>

int main(void) {
    ErrorCodes errorCode = noErrors;
    ErrorCodes* errorCodePointer = &errorCode;

    Dictionary* myDictionary = createDictionary(errorCodePointer);
    if (errorCode) {
        return -1;
    }

    char* string1 = "abraca";
    char* string2 = "lorem ipsum";

    addValue(string1, 5, myDictionary, errorCodePointer);
    addValue(string2, 0, myDictionary, errorCodePointer);
    if (*errorCodePointer) {
        return -1;
    }

    Value nonExistingStringFromDictionary = getValueByKey(1, myDictionary, errorCodePointer);

    return 0;
}