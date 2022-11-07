#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

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
// Требует подключения time.h и stdlib.h
void arrayGenerate(int* arrayToGen, int wantedSize) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < wantedSize; ++i)
        arrayToGen[i] = (rand() % 1000);
}

// Функция для вывода массива на экран.
// Принимает указатель на массив, размер массива и количество элементов в одной строке вывода.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString) {
    for (int i = 1; i < printingArraySize + 1; ++i) {
        printf("%7d", arrayToPrint[i - 1]);
        if (i % numberOfElementsInOneString == 0)
            printf("\n");
    }

    printf("\n\n");
}

// Функция бинарного поиска числа в массиве.
// На вход принимает указатель на массив, искомое число и левый и правый индексы части массива, в которой ищем.
// Корректно работает только на отсортированном массиве.
bool search(int* array, int value, int left, int right) {
    int arrayLength = right - left + 1;

    if (arrayLength < 3) {
        if (array[left] == value || array[right] == value)
            return true;
        return false;
    }

    int middleIndex = left + (arrayLength / 2);
    int middleValue = array[middleIndex];

    if (value = middleValue)
        return true;
    if (value < middleValue)
        return search(array, value, left, middleIndex - 1);
    if (value > middleValue)
        return search(array, value, middleIndex + 1, right);

    return false;
}

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

        printf("Calling qsort with %d and %d AND %d and %d\n", leftIndex, left - 1, left + 1, rightIndex);
        quickSort(array, leftIndex, left - 1);
        quickSort(array, left + 1, rightIndex);
    }

    return;
}

bool test(void) {

}

int main(void) {
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

    /*for (int i = 0; i < k; ++i) {
        if (search(randomArray, numbersForSearch[i], 0, k - 1))
            printf("There is number %d in the random array\n", numbersForSearch[i]);
        else
            printf("There is NO number %d in the random array\n", numbersForSearch[i]);
    }*/

    quickSort(randomArray, 0, n - 1);

    printf("Sorted first array (n):\n");
    arrayPrint(randomArray, n, 10);

    return 0;
}