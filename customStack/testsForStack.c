#include "testsForStack.h"

#include <stdlib.h>

// “ест создани€ и удалени€ стека.
// True - тест успешно пройден, false в обратном случае.
bool testForCreateAndDeleteStack(void) {
    ErrorCodes errorCode = noErrors;

    Stack* testStack = NULL;

    testStack = createStack(&errorCode);
    if (testStack == NULL || errorCode) {
        return false;
    }

    deleteStack(testStack, &errorCode);
    if (errorCode) {
        return false;
    }

    return true;
}

// “ест добавлени€ элемента в стек и удалени€ элемента из стека.
// True - тест успешно пройден, false в обратном случае.
bool testForPushAndPop(void) {
    ErrorCodes errorCode = noErrors;

    Stack* testStack = createStack(&errorCode);
    if (testStack == NULL || errorCode) {
        return false;
    }

    push(10, testStack, &errorCode);
    if (errorCode) {
        return false;
    }

    Value testValue = pop(testStack, &errorCode);
    if (errorCode || testValue != 10) {
        return false;
    }

    deleteStack(testStack, &errorCode);
    if (errorCode) {
        return false;
    }

    return true;
}

// “ест функций очистки стека и проверки его на пустоту.
// True - тест успешно пройден, false в обратном случае.
bool testForClearAndIsEmpty(void) {
    ErrorCodes errorCode = noErrors;

    Stack* testStack = createStack(&errorCode);
    if (testStack == NULL || errorCode) {
        return false;
    }

    bool emptynessTest1 = isEmpty(testStack, &errorCode);
    if (errorCode) {
        return false;
    }

    push(10, testStack, &errorCode);
    push(20, testStack, &errorCode);

    bool emptynessTest2 = isEmpty(testStack, &errorCode);
    if (errorCode) {
        return false;
    }

    clear(testStack, &errorCode);
    if (errorCode) {
        return false;
    }

    bool emptynessTest3 = isEmpty(testStack, &errorCode);

    if (errorCode || !emptynessTest1 || emptynessTest2 || !emptynessTest3) {
        return false;
    }

    return true;
}
