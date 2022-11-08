#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Функция для обработки пользовательского ввода (целые числа).
// На вход принимает указатель на переменную, в которую нужно записать значение.
void input(int* value) {
    int correctnessCheck = scanf_s("%d", value);

    while (!correctnessCheck) {
        scanf_s("%*[^\n]");
        printf("Invalid input. Try again:\n");
        correctnessCheck = scanf_s("%d", value);
    }

    scanf_s("%*[^\n]");
    return;
}

// Сгенерировать массив размера wantedSize.
// На вход принимает указатель на пустой массив и желаемое количество элементов.
void arrayGenerate(int* arrayToGen, int wantedSize) {
    for (int i = 0; i < wantedSize; ++i) {
        arrayToGen[i] = (rand() % 1000);
    }
}

// Функция для вывода массива на экран.
// Принимает указатель на массив, размер массива и количество элементов в одной строке вывода.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString) {
    int stringsCounter = 1;

    for (int i = 0; i < printingArraySize; ++i) {
        if (i % (numberOfElementsInOneString + 1) == 0) {
            printf("\n%4d |", stringsCounter);
            stringsCounter++;
        }
        printf("%7d", arrayToPrint[i]);
    }

    printf("\n\n");
}

// Функция бинарного поиска числа в массиве.
// На вход принимает указатель на массив, искомое число и левый и правый индексы части массива, в которой ищем.
// Возвращает true, если нашла искомое число в данном массиве, и false в противном случае.
// Корректно работает только на отсортированном массиве.
bool search(int* array, int value, int left, int right) {
    int arrayLength = right - left + 1;

    if (arrayLength < 3) {
        if (array[left] == value || array[right] == value) {
            return true;
        }

        return false;
    }

    int middleIndex = left + (arrayLength / 2);
    int middleValue = array[middleIndex];

    if (value == middleValue) {
        return true;
    }
    if (value < middleValue) {
        return search(array, value, left, middleIndex - 1);
    }
    if (value > middleValue) {
        return search(array, value, middleIndex + 1, right);
    }

    return false;
}

// Функция быстрой сортировки.
// На вход принимает указатель на сортируемый массив и левый и правый индексы сортируемого куска массива.
void quickSort(int* array, int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int left = leftIndex;
        int right = leftIndex;
        int separator = array[rightIndex];

        while (right < rightIndex) {
            if (array[right] < separator) {
                int temporary = array[left];
                array[left] = array[right];
                array[right] = temporary;

                left++;
            }

            right++;
        }

        int temporary = array[rightIndex];
        array[rightIndex] = array[left];
        array[left] = temporary;

        if (leftIndex < left - 1) {
            quickSort(array, leftIndex, left - 1);
        }
        if (left + 1 < rightIndex) {
            quickSort(array, left + 1, rightIndex);
        }
    }

    return;
}

// Далее две функции тестов, отдельно для функции сортировки и поиска.
// Если обе функции работают корректно, то их "композиция" тоже будте работать корректно.
bool testForSort(void) {
    bool test1 = true;
    int testArray1[] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int referenceArray1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    quickSort(testArray1, 0, 10);

    for (int i = 0; i < 11; ++i) {
        if (testArray1[i] != referenceArray1[i]) {
            test1 = false;
        }
    }

    bool test2 = true;
    int testArray2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int referenceArray2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    quickSort(testArray2, 0, 10);

    for (int i = 0; i < 11; ++i) {
        if (testArray2[i] != referenceArray2[i]) {
            test2 = false;
        }
    }

    bool test3 = true;
    int testArray3[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int referenceArray3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

    quickSort(testArray3, 0, 10);

    for (int i = 0; i < 11; ++i) {
        if (testArray3[i] != referenceArray3[i]) {
            test3 = false;
        }
    }

    if (test1 && test2 && test3) {
        return true;
    }
    else {
        return false;
    }
}

bool testForSearch(void) {
    bool test1 = true;
    int testArray1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    if (!search(testArray1, 11, 2, 10)) {
        test1 = false;
    }

    bool test2 = true;
    int testArray2[] = { 0 };

    if (!search(testArray2, 0, 0, 0)) {
        test2 = false;
    }

    if (test1 && test2) {
        return true;
    }
    else {
        return false;
    }
}

int main(void) {
    if (testForSort() && testForSearch()) {
        printf("*Tests passed*\n\n");
    }
    else {
        printf(testForSort() ? "Sort test passed\n" : "Sort test failed\n");
        printf(testForSearch() ? "Search test passed\n" : "Search test failed\n");
        return -1;
    }

    srand((unsigned)time(NULL));

    int n = 0;
    int k = 0;
      
    printf("Enter n:\n");
    input(&n);
    printf("Enter k:\n");
    input(&k);

    int* randomArray = calloc(n, sizeof(int));
    if (randomArray == NULL) {
        printf("Memory allocation problems\n");
        return -1;
    }

    arrayGenerate(randomArray, n);

    printf("First array (n):\n");
    arrayPrint(randomArray, n, 10);

    int* numbersForSearch = calloc(k, sizeof(int));
    if (numbersForSearch == NULL) {
        printf("Memory allocation problems\n");
        return -1;
    }

    arrayGenerate(numbersForSearch, k);

    printf("Second array (k)\n");
    arrayPrint(numbersForSearch, k, 10);

    quickSort(randomArray, 0, n - 1);

    printf("Sorted first array (n):\n");
    arrayPrint(randomArray, n, 10);

    for (int i = 0; i < k; ++i) {
        if (search(randomArray, numbersForSearch[i], 0, n - 1)) {
            printf("There is number %d in the random array\n", numbersForSearch[i]);
        }
        else {
            printf("There is NO number %d in the random array\n", numbersForSearch[i]);
        }
    }

    return 0;
}