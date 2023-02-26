#include <stdio.h>
#include <stdbool.h>

// Сортировка пузырьком.
// На вход принимает указатель на сортируемый массив и его размер.
void bubbleSort(int* arrayToSort, int arraySize) {
    bool wereThereSwaps = true;
    int counterOfPasses = 0;

    while (wereThereSwaps) {
        wereThereSwaps = false;

        for (int i = 0; i < arraySize - 1 - counterOfPasses; ++i) {
            if (arrayToSort[i] > arrayToSort[i + 1]) {
                int temporary = arrayToSort[i];
                arrayToSort[i] = arrayToSort[i + 1];
                arrayToSort[i + 1] = temporary;

                wereThereSwaps = true;
            }
        }

        counterOfPasses++;
    }
}