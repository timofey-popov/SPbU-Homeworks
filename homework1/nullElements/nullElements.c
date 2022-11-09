#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Функция подсчёта нулей в массиве.
// На вход принимает указатель на массив и его размер.
// Возвращает целое число - количество нулевых элементов.
int nullCounter(int* arrayForCounting, size_t arraySize) {
    int counter = 0;

    for (size_t i = 0; i < arraySize; ++i) {
        if (arrayForCounting[i] == 0) {
            ++counter;
        }
    }

    return counter;
}

// Функция заполнения массива случайными числами от -5 до 4.
// На вход принимает указатель на массив и размер массива.
void arrayGenerate(int* arrayToGen, int wantedSize) {
    srand(time(NULL));
    for (int i = 0; i < wantedSize; ++i) {
        arrayToGen[i] = (rand() % 10) - 5;
    }
}

// Функция, которая выводит массив на экран.
// На вход принимает указатель на массив, его размер и количество элементов в одной строке вывода.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString) {
    for (int i = 1; i < printingArraySize + 1; ++i) {
        printf("%6d", arrayToPrint[i - 1]);
        if (i % numberOfElementsInOneString == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main(void) {
    int nullStorage[1000] = { 0 };
    const size_t arraySize = sizeof(nullStorage) / sizeof(int);

    arrayGenerate(nullStorage, arraySize);
    printf("Generated array:\n");
    arrayPrint(nullStorage, arraySize, 14);

    printf("\nThere are %d zeroes in this array.\n", nullCounter(nullStorage, arraySize));

    return 0;
}
