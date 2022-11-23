#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "task1.h"

// Тест для функций пуш и клир.
bool testForPushAndClear(void) {
    Unit* head = NULL;
    Unit* tail = NULL;

    int pushCorrectnessCheck = push(20, &head, &tail);

    if (pushCorrectnessCheck) {
        return false;
    }

    int clearCorrectnessCheck = clear(&tail);
    if (clearCorrectnessCheck) {
        return false;
    }

    clearCorrectnessCheck = clear(&tail);
    if (!clearCorrectnessCheck) {
        return false;
    }

    return true;
}

// Тест для функции филл.
bool testForFill(void) {
    Unit* head = NULL;
    Unit* tail = NULL;

    FILE* testFile = fopen("testFileRightCase.txt", "r");
    if (testFile == NULL) {
        printf("Cannot open the test file\n");
        return false;
    }

    int fillCorrectnessCheck = fill(testFile, &head, &tail);

    clear(&tail);
    fclose(testFile);

    return !fillCorrectnessCheck;
}

// Тест для функции из симметрикал.
bool testForIsSymmetrical(void) {
    int testErrorCode = 0;

    Unit* head = NULL;
    Unit* tail = NULL;

    FILE* testRightFile = fopen("testFileRightCase.txt", "r");
    if (testRightFile == NULL) {
        printf("Cannot open the test file\n");
        return false;
    }

    fill(testRightFile, &head, &tail);

    bool isCorrect = isSymmetrical(&head, &tail, &testErrorCode);

    if (testErrorCode || !isCorrect) {
        return false;
    }

    clear(&tail);
    fclose(testRightFile);

    FILE* testWrongFile = fopen("testFileWrongCase.txt", "r");
    if (testWrongFile == NULL) {
        printf("Cannot open the test file\n");
        return false;
    }

    fill(testWrongFile, &head, &tail);

    isCorrect = isSymmetrical(&head, &tail, &testErrorCode);

    if (testErrorCode || isCorrect) {
        return false;
    }

    clear(&tail);
    fclose(testWrongFile);

    return true;

}