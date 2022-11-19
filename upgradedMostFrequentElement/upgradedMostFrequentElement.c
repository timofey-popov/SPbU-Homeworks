#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

// Функция, считающая самый частый элемент в массиве.
// На вход принимает ссылку на массив и его размер, возвращает значение самого частого элемента.
int mostFrequentElement(int* arrayToOperate, size_t arraySize) {
    quickSort(arrayToOperate, 0, arraySize - 1);

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

// Функция-тест
bool test(void) {
    int testArray1[] = { 1, 2, 3, 4, 4, 5 };
    int testArray2[] = { 0, 0, 0, 0, 0, 0 };
    int testArray3[] = { 1, 2, 3, 4, 5, 6 };

    return (mostFrequentElement(testArray1, 6) == 4 && mostFrequentElement(testArray2, 6) == 0 && mostFrequentElement(testArray3, 6) == 1);
}

int main(void) {
    if (!test()) {
        printf("Test failed.\n");
        return -1;
    } else {
        printf("*test passed*\n\n");
    }

    int arrayToOperate[] = { 1, 5, 5, 6, 2, 3, 4, 7, 5, 1, 2, 3, 1, 1 };
    size_t sizeOfArray = sizeof(arrayToOperate) / sizeof(int);

    printf("Most frequent element = %d\n", mostFrequentElement(arrayToOperate, sizeOfArray));

    return 0;
}