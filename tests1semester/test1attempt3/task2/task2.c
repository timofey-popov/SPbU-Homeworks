#include <stdio.h>
#include <stdbool.h>

// Функция сортировки выбором только элементов массива с чётными индексами.
// На вход принимает указатель на массив целых чисел и его размер.
void selectionSortForNumbersWithEvenIndexes(int* array, int arraySize) {
    for (int i = 0; i < arraySize; i += 2) {

        int minimumNumberIndex = i;

        for (int j = i + 2; j < arraySize; j += 2) {
            if (array[j] < array[i]) {
                minimumNumberIndex = j;
            }
        }

        if (minimumNumberIndex != i) {
            int temporary = array[i];
            array[i] = array[minimumNumberIndex];
            array[minimumNumberIndex] = temporary;
        }
    }
}

// Функция для вывода массива на экран.
// Принимает указатель на массив, размер массива и количество элементов в одной строке вывода.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString) {

    for (int i = 0; i < printingArraySize; ++i) {
        if (i % (numberOfElementsInOneString) == 0) {
            printf("\n");
        }
        printf("%7d", arrayToPrint[i]);
    }

    printf("\n\n");
}

// Функция с тестами.
// Проверяет работу функции сортировки на стандартном массиве, отсортированном в обратном порядке,
// и проверяет, что сортировка не портит уже отсортированный массив.
bool testForSort(void) {
    bool test1 = true;
    int testArray1[] = { 5, 4, 3, 2, 1 };
    int referenceArray1[] = { 1, 4, 3, 2, 5 };

    selectionSortForNumbersWithEvenIndexes(testArray1, 5);

    for (int i = 0; i < 5; ++i) {
        if (testArray1[i] != referenceArray1[i]) {
            test1 = false;
        }
    }

    bool test2 = true;
    int testArray2[] = { 1, 4, 3, 2, 5 };
    int referenceArray2[] = { 1, 4, 3, 2, 5 };

    selectionSortForNumbersWithEvenIndexes(testArray2, 5);

    for (int i = 0; i < 5; ++i) {
        if (testArray2[i] != referenceArray2[i]) {
            test2 = false;
        }
    }

    if (test1 && test2) {
        return true;
    }
    else {
        return false;
    }
}

int main(void) {
    if (!testForSort()) {
        printf("Test failed\n\n");
        return -1;
    }
    printf("*Test passed*\n\n");

    int arrayForSort[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int arraySize = sizeof(arrayForSort) / sizeof(int);

    printf("Initial array:\n");
    arrayPrint(arrayForSort, 10, 10);

    selectionSortForNumbersWithEvenIndexes(arrayForSort, arraySize);

    printf("Sorted array:\n");
    arrayPrint(arrayForSort, 10, 10);

    return 0;
}