#include <stdio.h>
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

    return;
}

// Четыре функции тестов, проверяющих разные случаи.
bool test1(void) {
    int testArray1[] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int referenceArray1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    quickSort(testArray1, 0, 10);

    for (int i = 0; i < 11; ++i) {
        if (testArray1[i] != referenceArray1[i])
            return false;
    }

    return true;
}

bool test2(void) {
    int testArray2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int referenceArray2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    quickSort(testArray2, 0, 10);

    for (int i = 0; i < 11; ++i) {
        if (testArray2[i] != referenceArray2[i])
            return false;
    }

    return true;
}

bool test3(void) {
    int testArray3[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int referenceArray3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

    quickSort(testArray3, 0, 10);

    for (int i = 0; i < 11; ++i) {
        if (testArray3[i] != referenceArray3[i])
            return false;
    }

    return true;
}

bool test4(void) {
    int testArray4[] = { 1, 0 };
    int referenceArray4[] = { 0, 1 };

    quickSort(testArray4, 0, 1);

    for (int i = 0; i < 2; ++i) {
        if (testArray4[i] != referenceArray4[i])
            return false;
    }

    return true;
}

int main(void) {
    if (!test1() || !test2() || !test3() || !test4()) {
        printf("Test 1 = %d, test 2 = %d, test 3 = %d, test 4 = %d;\n", test1(), test2(), test3(), test4());
        printf("Tests failed.\n");
        return -1;
    }

    int arrayToSort[] = { 5, 2, 2, 5, 3, 4, 6, 1, 2, 1, 10, 16, 10, 3, 4, 121 };
    size_t sizeOfArray = sizeof(arrayToSort) / sizeof(int);

    quickSort(arrayToSort, 0, sizeOfArray - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < sizeOfArray; ++i) {
        printf("%d ", arrayToSort[i]);
    }

    return 0;
}