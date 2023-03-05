#include "tests.h"
#include "circularList.h"

#include <stdlib.h>

// Тест для функций создания и удаления списка.
bool testForCreateAndDeleteList(void) {
    ListErrors testErrorCode = noErrorsInList;

    CircularList* testList = createList(&testErrorCode);
    if (testErrorCode || (testList == NULL)) {
        return false;
    }

    deleteList(testList, &testErrorCode);

    return !testErrorCode;
}

// Тест для разных сценариев добавления и удаления элементов из списка.
bool testForAddAndDeleteValue(void) {
    ListErrors testErrorCode = noErrorsInList;

    CircularList* testList = createList(&testErrorCode);
    if (testErrorCode || (testList == NULL)) {
        return false;
    }

    deleteFromList(100, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(1, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(50, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(1, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(-6, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(15, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(3, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(15, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(20, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(-6, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(20, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteList(testList, &testErrorCode);

    return !testErrorCode;
}

bool testForCalculating(void) {
    ListErrors testErrorCode = noErrorsInList;

    // Легко проверить вручную.
    int test1 = calculateSuitablePosition(5, 2, &testErrorCode);

    // Всегда должен возвращать 1.
    int test2 = calculateSuitablePosition(1, 100, &testErrorCode);
    
    // При двух воинах должно возвращаться 1, если m чётное, и 2 в противном случае.
    int test3 = calculateSuitablePosition(2, 120, &testErrorCode);
    int test4 = calculateSuitablePosition(2, 159, &testErrorCode);

    // Всегда должен возвращать последнюю позицию.
    int test5 = calculateSuitablePosition(120, 1, &testErrorCode);
    int test6 = calculateSuitablePosition(3, 1, &testErrorCode);

    return (test1 == 3) && (test2 == 1) && (test3 == 1) && (test4 == 2) && (test5 == 120) && (test6 == 3);
}