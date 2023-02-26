#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Сортировка подсчётом.
// На вход принимает указатель на сортируемый массив и его размер.
// Возвращает -1, если не удалось выделение памяти под вспомогательный массив, и 0, если всё хорошо.
int countingSort(int* arrayToSort, int arraySize) {

    // Нахождение минимального и максимального элементов.
    int maximumElement = arrayToSort[0];
    int minimumElement = arrayToSort[0];

    for (int i = 1; i < arraySize; ++i) {
        if (arrayToSort[i] > maximumElement) {
            maximumElement = arrayToSort[i];
        }

        if (arrayToSort[i] < minimumElement) {
            minimumElement = arrayToSort[i];
        }
    }

    // Вычисление нужной длины вспомогательного массива и его создание.
    int serviceArrayLength = maximumElement - minimumElement + 1;
    int* serviceArray = calloc(serviceArrayLength, sizeof(int));

    if (serviceArray == NULL) {
        printf("Memory allocation error.");
        return -1;
    }

    int shift = -minimumElement;

    // Подсчёт количества вхождений элементов в изначальный массив.
    for (int i = 0; i < arraySize; ++i) {
        serviceArray[arrayToSort[i] + shift]++;
    }

    // Заполнение изначального массива.
    int filledPlacesCounter = 0;

    for (int i = 0; i < serviceArrayLength; ++i) {
        for (int j = 0; j < serviceArray[i]; ++j) {
            arrayToSort[filledPlacesCounter] = i - shift;
            filledPlacesCounter++;
        }
    }

    free(serviceArray);

    return 0;
}
