#include <stdio.h>
#include <stdbool.h>

#define ARRAYSIZE 11

// Тело отражающей функции.
// 
// Принимает на вход указатель на массив и номера первого и последнего
// элементов участка массива, который нужно отразить.
//
// Меняет местами первый и последний элемент участка, затем второй и предпоследний и т. д.
void reverse(int* arrayForReverse, int firstReverseElement, int lastReverseElement) {
    char temporary = 0;
    int operationCounter = 0;

    for (int i = firstReverseElement - 1; i < (firstReverseElement + ((lastReverseElement - firstReverseElement) / 2)); ++i) {
        temporary = arrayForReverse[i];
        arrayForReverse[i] = arrayForReverse[lastReverseElement - 1 - operationCounter];
        arrayForReverse[lastReverseElement - 1 - operationCounter] = temporary;

        operationCounter++;
    }
}

// Распечатывает массив фиксированного размера, на вход принимает указатель на него.
void printArray(int* arrayToPrint) {
    for (int i = 0; i < ARRAYSIZE; ++i)
        printf("%d ", arrayToPrint[i]);
    printf("\n");
}

// Определение массива, переменных m и n, применение к нему отражающей функции,
// распечатка массива после каждого применения функции.

int main(void)
{
    int arrayToChange[ARRAYSIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int m = 4;
    int n = 7;

    printf("Initial array:\n");
    printArray(arrayToChange);

    reverse(arrayToChange, 1, m);

    printf("\nArray after first part reverse:\n");
    printArray(arrayToChange);

    reverse(arrayToChange, m + 1, m + n);
    
    printf("\nArray after second part reverse:\n");
    printArray(arrayToChange);

    reverse(arrayToChange, 1, m + n);

    printf("\nArray with the first and second parts switched:\n");
    printArray(arrayToChange);

    return 0;
}