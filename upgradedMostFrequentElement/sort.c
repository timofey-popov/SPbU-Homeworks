#include "sort.h"

#include <stdbool.h>

// Функция разделения массива на две части.
// Слева элементы меньшие либо равные последнему элементу массива, справа - бОльшие последнего.
// В конце выполнения помещает последний элемент (разделитель) между этими двумя частями массива.
// Возвращает индекс этого элемента-разделителя.
int partition(int* arrayToSort, int leftElementNumber, int rightElementNumber) {
    int pivot = arrayToSort[rightElementNumber];

    int i = leftElementNumber;
    for (int j = leftElementNumber; j < rightElementNumber; ++j) {
        if (arrayToSort[j] <= pivot) {
            int temporary = arrayToSort[i];
            arrayToSort[i] = arrayToSort[j];
            arrayToSort[j] = temporary;

            ++i;
        }
    }

    int temporary = arrayToSort[i];
    arrayToSort[i] = arrayToSort[rightElementNumber];
    arrayToSort[rightElementNumber] = temporary;

    return i;
}

// Рекурсивная функция быстрой сортировки.
// Вызывает себя от начала до индекса, возвращаемого функцией разделения, - 1, и от индекса + 1 до конца массива.
// Сам элемент с индексом, возвращённым функцией разделения, оставляет на месте.
// Если элементов в массиве меньше 10, функция сортирует их обычными вставками.
void quickSort(int* arrayToSort, int leftElementNumber, int rightElementNumber) {
    if ((rightElementNumber - leftElementNumber + 1) < 10) {
        for (int i = leftElementNumber + 1; i < rightElementNumber + 1; ++i) {
            int k = i;
            while (k > leftElementNumber && arrayToSort[k] < arrayToSort[k - 1]) {
                int temporary = arrayToSort[k];
                arrayToSort[k] = arrayToSort[k - 1];
                arrayToSort[k - 1] = temporary;

                k--;
            }
        }
    }

    else if (leftElementNumber < rightElementNumber) {
        int separator = partition(arrayToSort, leftElementNumber, rightElementNumber);
        quickSort(arrayToSort, leftElementNumber, separator - 1);
        quickSort(arrayToSort, separator + 1, rightElementNumber);
    }
}