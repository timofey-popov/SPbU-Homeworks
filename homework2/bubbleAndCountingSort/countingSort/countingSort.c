#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Функция для вывода массива на экран.
// Принимает указатель на массив, размер массива и количество элементов в одной строке вывода.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString) {
    for (int i = 1; i < printingArraySize + 1; ++i) {
        printf("%7d", arrayToPrint[i - 1]);
        if (i % numberOfElementsInOneString == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

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

// Далее расположены три функции с тестами.
// Возвращают true в случае, если всё работает правильно и false в противном случае.
bool test1(void) {
    int testArray1[5] = { 0, 0, 0, 0, 0 };
    int referenceArray1[5] = { 0, 0, 0, 0, 0 };

    int correctnessCheck = countingSort(testArray1, 5);
    if (correctnessCheck) {
        return false;
    }

    for (int i = 0; i < 5; ++i) {
        if (testArray1[i] != referenceArray1[i]) {
            return false;
        }
    }

    return true;
}

bool test2(void) {
    int testArray2[5] = { 5, 5, 5, 4, 3 };
    int referenceArray2[5] = { 3, 4, 5, 5, 5 };

    int correctnessCheck = countingSort(testArray2, 5);
    if (correctnessCheck) {
        return false;
    }

    for (int i = 0; i < 5; ++i) {
        if (testArray2[i] != referenceArray2[i]) {
            return false;
        }
    }

    return true;
}

bool test3(void) {
    int testArray3[5] = { 5, 4, 3, 2, 1 };
    int referenceArray3[5] = { 1, 2, 3, 4, 5 };

    int correctnessCheck = countingSort(testArray3, 5);
    if (correctnessCheck) {
        return false;
    }
    
    for (int i = 0; i < 5; ++i) {
        if (testArray3[i] != referenceArray3[i]) {
            return false;
        }
    }

    return true;
}

bool test4(void) {
    int testArray4[5] = { 1, 2, 3, 4, 5};
    int referenceArray4[5] = { 1, 2, 3, 4, 5 };

    int correctnessCheck = countingSort(testArray4, 5);
    if (correctnessCheck) {
        return false;
    }

    for (int i = 0; i < 5; ++i) {
        if (testArray4[i] != referenceArray4[i]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    if (!test1() || !test2() || !test3() || !test4) {
        printf("Test 1: %d, Test 2: %d, Test 3: %d, Test 4: %d\n", test1(), test2(), test3(), test4());
        printf("Tests failed.\n");
        return -1;
    } else {
        printf("*tests passed*\n\n");
    }

    int initialArray[] = {0, 5, 3, 6, 16, 4, 747, 45, -10, -20, 3, 17, 16, 0, 15};
    int sizeOfArray = sizeof(initialArray) / sizeof(int);

    printf("Initial condition of array:\n");
    arrayPrint(initialArray, sizeOfArray, 5);

    int correctnessCheck = countingSort(initialArray, sizeOfArray);
    if (correctnessCheck) {
        return -1;
    }

    printf("Sorted array:\n");
    arrayPrint(initialArray, sizeOfArray, 5);

    return 0;
}