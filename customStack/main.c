#include <stdio.h>
#include "customStack.h"
#include "testsForStack.h"

int main(void) {
    if (!testForCreateAndDeleteStack() || !testForPushAndPop() || !testForClearAndIsEmpty()) {
        printf("Tests failed.\n");
        return -1;
    }
    else {
        printf("*tests passed*\n\n");
    }

    ErrorCodes errorCode = noErrors;

    Stack* newStack = createStack(&errorCode);
    if (errorCode) {
        return errorCode;
    }

    push(10, newStack, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    push(100, newStack, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    printf("%d\n\n", isEmpty(newStack, &errorCode));
    if (errorCode) {
        return errorCode;
    }

    printStack(newStack, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    printf("%d\n\n", pop(newStack, &errorCode));
    if (errorCode) {
        return errorCode;
    }

    clear(newStack, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    printf("%d\n\n", isEmpty(newStack, &errorCode));
    if (errorCode) {
        return errorCode;
    }

    deleteStack(newStack, &errorCode);
    if (errorCode) {
        return errorCode;
    }
}
