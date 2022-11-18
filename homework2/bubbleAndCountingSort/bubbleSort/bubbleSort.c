#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Функция для вывода массива на экран.
// Принимает указатель на массив, размер массива и количество элементов в одной строке вывода.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString) {
    for (int i = 1; i < printingArraySize + 1; ++i) {
        printf("%15d", arrayToPrint[i - 1]);
        if (i % numberOfElementsInOneString == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

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

//Функция с тестами.
//Возвращает true в случае, если всё работает правильно и false в противном случае.
bool testBubbleSort(int* numberOfFailedTest) {
    int testArrays[4][5] = { { 0, 0, 0, 0, 0 }, { 5, 5, 5, 4, 3 }, { 5, 4, 3, 2, 1 }, { 1, 2, 3, 4, 5 } };
    int referenceArrays[4][5] = { { 0, 0, 0, 0, 0 }, { 3, 4, 5, 5, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 } };

    for (int i = 0; i < 4; ++i) {
        bubbleSort(testArrays[i], 5);

        if (!comparisonForTest(testArrays[i], referenceArrays[i], 5)) {
            *numberOfFailedTest = i + 1;
            return false;
        }
    }

    return true;
}

int main(void) {
    int numberOfFailedTest = 0;
    if (!testBubbleSort(&numberOfFailedTest)) {
        printf("Tests %d failed.\n", numberOfFailedTest);
        return -1;
    } else {
        printf("*tests passed*\n\n");
    }

    int initialArray[] = { 0, 5, 3, 6, 16, 4, 747, 45, -10, -20, 3, 17, 16, 0, 15 };
    int sizeOfArray = sizeof(initialArray) / sizeof(int);

    printf("Initial condition of array:\n");
    arrayPrint(initialArray, sizeOfArray, 5);

    bubbleSort(initialArray, sizeOfArray);

    printf("Sorted array:\n");
    arrayPrint(initialArray, sizeOfArray, 5);

    return 0;
}