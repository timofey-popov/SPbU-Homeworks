#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "../bubbleSort/bubbleSort.h"
#include "../countingSort/countingSort.h"

// Сгенерировать массив размера wantedSize.
void arrayGenerate(int* arrayToGen, int wantedSize) {
    for (int i = 0; i < wantedSize; ++i)
        arrayToGen[i] = (rand() % 1000);
}

// Функция для вывода массива на экран.
// Принимает указатель на массив, размер массива и количество элементов в одной строке вывода.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString) {
    for (int i = 1; i < printingArraySize + 1; ++i) {
        printf("%7d", arrayToPrint[i - 1]);
        if (i % numberOfElementsInOneString == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

// Функция для сравнения отсортированного массива с образцом.
// На вход принимает указатели на эти два массива и их размер.
// В цикле бежит по соответсвующим элементам массива и сравнивает их.
// Возвращает true, если массивы совпадают, и false в противном случае.
bool comparisonForTest(int* arrayForTest, int* referenceArray, size_t arraySize) {
    for (size_t i = 0; i < arraySize; ++i) {
        if (arrayForTest[i] != referenceArray[i]) {
            return false;
        }
    }
    
    return true;
}

// Функция с тестами.
// Прогоняет тесты сначала для сортировки пузырьком, потом для сортировки подсчётом.
// Возвращает true в случае, если всё работает правильно и false в противном случае.
bool testForSorts(int* errorCode) {
    int testArraysForBubble[4][5] = { { 0, 0, 0, 0, 0 }, { 5, 5, 5, 4, 3 }, { 5, 4, 3, 2, 1 }, { 1, 2, 3, 4, 5 } };
    int referenceArrays[4][5] = { { 0, 0, 0, 0, 0 }, { 3, 4, 5, 5, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 } };

    for (int i = 0; i < 4; ++i) {
        bubbleSort(testArraysForBubble[i], 5);

        if (!comparisonForTest(testArraysForBubble[i], referenceArrays[i], 5)) {
            *errorCode = 1;
            return false;
        }
    }

    int testArraysForCounting[4][5] = { { 0, 0, 0, 0, 0 }, { 5, 5, 5, 4, 3 }, { 5, 4, 3, 2, 1 }, { 1, 2, 3, 4, 5 } };

    for (int i = 0; i < 4; ++i) {
        countingSort(testArraysForCounting[i], 5);

        if (!comparisonForTest(testArraysForCounting[i], referenceArrays[i], 5)) {
            *errorCode = 2;
            return false;
        }
    }

    return true;
}

int main(void) {
    int testsErrorCode = 0;

    if (!testForSorts(&testsErrorCode)) {
        printf("Tests %d failed.\n1 - bubble sort, 2 - counting sort\n", testsErrorCode);
        return -1;
    } else {
        printf("*tests passed*\n");
    }

    srand((unsigned)time(NULL));

    int* arrayForSort = calloc(100000, sizeof(int));
    int* arrayForSortCopy = calloc(100000, sizeof(int));
    if (arrayForSort == NULL || arrayForSortCopy == NULL) {
        free(arrayForSort);
        free(arrayForSortCopy);
        printf("Memory allocation error\n");
        return -1;
    }

    arrayGenerate(arrayForSort, 100000);

    for (int i = 0; i < 100000; ++i) {
        arrayForSortCopy[i] = arrayForSort[i];
    }

    time_t beginBubbleSort = time(NULL);
    bubbleSort(arrayForSort, 100000);
    time_t endBubbleSort = time(NULL);


    time_t beginCountingSort = time(NULL);
    int errorCode = countingSort(arrayForSortCopy, 100000);
    if (errorCode == -1) {
        free(arrayForSort);
        free(arrayForSortCopy);
        printf("Memory allocation error.\n");
        return -1;
    }
    time_t endCountingSort = time(NULL);

    printf("Bubble sort time: %lld seconds\n", endBubbleSort - beginBubbleSort);
    printf("Counting sort time: %lld seconds\n", endCountingSort - beginCountingSort);

    free(arrayForSort);
    free(arrayForSortCopy);

    return 0;
}