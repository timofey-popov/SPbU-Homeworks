#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "task1.h"

// Тест для функций createList и deleteList.
bool testForCreateAndDeleteList(void) {
    int errorCode = 0;
    DoublyLinkedList* testList = createDoublyLinkedList(&errorCode);
    if (errorCode || testList == NULL) {
        return false;
    }

    deleteList(testList, &errorCode);
    if (errorCode) {
        return false;
    }

    return true;
}

// Тест для функций push, isSymmetrical и clear.
// Сразу добавляем симметричные числа и проверяем, определяет ли это наша функция.
bool testForPushIsSymmetricalAndClear(void) {
    int errorCode = 0;
    DoublyLinkedList* testList = createDoublyLinkedList(&errorCode);
    if (errorCode || testList == NULL) {
        return false;
    }

    pushToTail(20, testList, &errorCode);
    if (errorCode) {
        return false;
    }

    pushToTail(10, testList, &errorCode);

    pushToTail(20, testList, &errorCode);

    bool isSymmetricalCorrectnessCheck = isSymmetrical(testList, &errorCode);
    if (errorCode || !isSymmetricalCorrectnessCheck) {
        return false;
    }

    clear(testList, &errorCode);
    if (errorCode) {
        return false;
    }

    deleteList(testList, &errorCode);

    return true;
}

// Тест для функции fill.
bool testForFill(void) {
    int errorCode = 0;
    DoublyLinkedList* testList = createDoublyLinkedList(&errorCode);
    if (errorCode || testList == NULL) {
        return false;
    }

    FILE* testFile = fopen("testFileRightCase.txt", "r");
    if (testFile == NULL) {
        return false;
    }

    fill(testFile, testList, &errorCode);
    if (errorCode) {
        printf("%d\n", errorCode);
        return false;
    }

    fclose(testFile);

    clear(testList, &errorCode);
    deleteList(testList, &errorCode);

    return true;
}

// Тест для ответа "false" функции isSymmetrical.
bool testForIsSymmetrical(void) {
    int errorCode = 0;
    DoublyLinkedList* testList = createDoublyLinkedList(&errorCode);
    if (errorCode || testList == NULL) {
        return false;
    }

    FILE* testWrongFile = fopen("testFileWrongCase.txt", "r");
    if (testWrongFile == NULL) {
        return false;
    }

    fill(testWrongFile, testList, &errorCode);
    if (isSymmetrical(testList, &errorCode) || errorCode) {
        return false;
    }

    fclose(testWrongFile);

    clear(testList, &errorCode);
    deleteList(testList, &errorCode);

    return true;
}