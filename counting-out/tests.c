#include "tests.h"
#include "circularList.h"

#include <stdlib.h>

// ���� ��� ������� �������� � �������� ������.
bool testForCreateAndDeleteList(void) {
    ListErrors testErrorCode = noErrorsInList;

    CircularList* testList = createList(&testErrorCode);
    if (testErrorCode || (testList == NULL)) {
        return false;
    }

    deleteList(testList, &testErrorCode);

    return !testErrorCode;
}

// ���� ��� ������ ��������� ���������� � �������� ��������� �� ������.
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

    // ����� ��������� �������.
    int test1 = calculateSuitablePosition(5, 2, &testErrorCode);

    // ������ ������ ���������� 1.
    int test2 = calculateSuitablePosition(1, 100, &testErrorCode);
    
    // ��� ���� ������ ������ ������������ 1, ���� m ������, � 2 � ��������� ������.
    int test3 = calculateSuitablePosition(2, 120, &testErrorCode);
    int test4 = calculateSuitablePosition(2, 159, &testErrorCode);

    // ������ ������ ���������� ��������� �������.
    int test5 = calculateSuitablePosition(120, 1, &testErrorCode);
    int test6 = calculateSuitablePosition(3, 1, &testErrorCode);

    return (test1 == 3) && (test2 == 1) && (test3 == 1) && (test4 == 2) && (test5 == 120) && (test6 == 3);
}