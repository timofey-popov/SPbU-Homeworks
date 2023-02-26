#include <stdio.h>
#include <stdbool.h>

#define ARRAYS_SIZE 10

void evenSelectionSort(int* arrayToSort, int sizeOfArray, int* arrayForEven, int* arrayForOdd) {
    // раскладываем элементы начального массива в два других: с чётными и нечётными индексами
    // считаем количество элементов "чётного" массива
    int evenElementsCounter = 0;

    for (int i = 0; i < sizeOfArray; ++i) {
        if (i % 2 == 0) {
            arrayForEven[i / 2] = arrayToSort[i];
            evenElementsCounter++;
        }

        else
            arrayForOdd[i / 2] = arrayToSort[i];
    }

    // делаем сортировку выбором только для "чётного" массива
    for (int i = 0; i < evenElementsCounter; ++i) {
        int currentMinElement = arrayForEven[0];
        int minElementIndex = 0;
        bool foundElementFlag = false;

        for (int j = i; j < evenElementsCounter; ++j) {
            if (arrayForEven[j] < currentMinElement) {
                currentMinElement = arrayForEven[j];
                minElementIndex = j;
                foundElementFlag = true;
            }
        }

        if (foundElementFlag) {
            int temporary = arrayForEven[i];
            arrayForEven[i] = arrayForEven[minElementIndex];
            arrayForEven[minElementIndex] = temporary;
        }
    }

    // сливаем два массива в один, чередуя чётные и нечётные элементы
    for (int i = 0; i < sizeOfArray; ++i) {
        if (i % 2 == 0)
            arrayToSort[i] = arrayForEven[i / 2];
        else
            arrayToSort[i] = arrayForOdd[i / 2];
    }
}

int main(void) {
    int initialArray[ARRAYS_SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int evenArray[ARRAYS_SIZE] = { 0 };
    int oddArray[ARRAYS_SIZE] = { 0 };

    evenSelectionSort(initialArray, ARRAYS_SIZE, evenArray, oddArray);

    for (int k = 0; k < ARRAYS_SIZE; ++k)
        printf("%d", initialArray[k]);

    return 0;
}