#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sort.h"

// Подсчёт количества чисел в файле, записанных через пробел.
int getArraySize(FILE* file) {
    int counter = 0;

    while (fscanf_s(file, "%*d") != EOF) {
        counter += 1;
    }

    rewind(file);
    return counter;
}

// Функция, считающая самый частый элемент в массиве.
// На вход принимает ссылку на массив и его размер, возвращает значение самого частого элемента.
int mostFrequentElementExecution(FILE* file, int* arrayToOperate, size_t arraySize) {

    quickSort(file, arrayToOperate);

    int counter = 1;
    int maximumCounter = 1;
    int frequentElement = arrayToOperate[0];

    for (size_t i = 1; i < arraySize; ++i) {
        if (arrayToOperate[i] == arrayToOperate[i - 1]) {
            counter++;
        }
        else {
            counter = 1;
        }

        if (counter > maximumCounter) {
            maximumCounter = counter;
            frequentElement = arrayToOperate[i];
        }
    }

    return frequentElement;
}

// Функция-тест.
// Возвращает true, если всё хорошо, и false в противном случае.
bool test(void) {
    FILE* testFile = fopen("testFileForMostFrequentElement.txt", "r");
    if (testFile == NULL) {
        return false;
    }

    int* testArray = calloc(getArraySize(testFile), sizeof(int));
    if (testArray == NULL) {
        return false;
    }

    return (mostFrequentElementExecution(testFile, testArray, getArraySize(testFile)) == 7);
}

int main(void) {
    if (!test()) {
        printf("Test failed.\n");
        return -1;
    }
    else {
        printf("*test passed*\n\n");
    }

    FILE* fileToSort = fopen("fileToSort.txt", "a+");
    if (fileToSort == NULL) {
        return -1;
    }

    int counterOfRecords = getArraySize(fileToSort);
    if (counterOfRecords == 0) {
        fclose(fileToSort);
        printf("No elements in file\n");
        return 0;
    }

    int* arrayToOperate = calloc(counterOfRecords, sizeof(int));
    if (arrayToOperate == NULL) {
        fclose(fileToSort);
        return -1;
    }

    printf("Most frequent element = %d\n", mostFrequentElementExecution(fileToSort, arrayToOperate, counterOfRecords));

    free(arrayToOperate);
    fclose(fileToSort);

    return 0;
}