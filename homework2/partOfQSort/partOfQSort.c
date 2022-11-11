#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>


// Функция, которая преобразует массив так, что в начале массива будут элементы, меньшие первого,
// а в конце — большие либо равные первому.
// На вход принимает указатель на массив для сортировки и его размер.
void partQSort(int* arrayToSort, int arraySize) {
    int separator = arrayToSort[0];
    int left = 0;
    int right = arraySize - 1;
    while (left < right) {
        while (arrayToSort[left] < separator && left < arraySize - 1) {
            left++;
        }

        while (arrayToSort[right] >= separator && right > 0) {
            right--;
        }

        if (left < right) {
            int temporary = arrayToSort[left];
            arrayToSort[left] = arrayToSort[right];
            arrayToSort[right] = temporary;
            ++left;
            --right;
        }
    }
}

// Функция, заполняющая массив случайными числами.
// На вход принимает указатель на массив и количество элементов, которые нужно сгенерировать.
void arrayGenerate(int* arrayToGen, int wantedSize) {
    for (int i = 0; i < wantedSize; ++i) {
        arrayToGen[i] = (rand() % 1000);
    }
}

// Функция, которая выводит массив на экран.
// На вход принимает указатель на массив и его размер.
void arrayPrint(int* arrayToPrint, int printingArraySize) {
    for (int i = 1; i < printingArraySize + 1; ++i) {
        printf("%10d", arrayToPrint[i - 1]);
        if (i % 5 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

// Далее расположены три функции с тестами. Проверяют две граничные ситуации и одну обычную.
// Возвращают true в случае, если всё работает правильно и false в противном случае.
bool test1(void) {
    int testArray1[10] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int referenceArray1[10] = { 9, 1, 2, 3, 4, 5, 6, 7, 8, 10 };
    partQSort(testArray1, 10);
    for (int i = 0; i < 10; ++i) {
        if (testArray1[i] != referenceArray1[i]) {
            return false;
        }
    }
    
    return true;
}

bool test2(void) {
    int testArray2[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    int referenceArray2[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    partQSort(testArray2, 10);
    for (int i = 0; i < 10; ++i) {
        if (testArray2[i] != referenceArray2[i]) {
            return false;
        }
    }

    return true;
}

bool test3(void) {
    int testArray3[10] = { 5, 7, 2, 6, 3, 5, 3, 10, 0, 1 };
    int referenceArray3[10] = { 1, 0, 2, 3, 3, 5, 6, 10, 7, 5 };

    partQSort(testArray3, 10);
    for (int i = 0; i < 10; ++i) {
        if (testArray3[i] != referenceArray3[i]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    if (!test1() || !test2() || !test3()) {
        printf("Test 1: %d, Test 2: %d, Test 3: %d\n", test1(), test2(), test3());
        printf("Tests failed.\n");
        return -1;
    } else {
        printf("*tests passed*\n\n");
    }

    srand(time(NULL));

    int inputArray[100] = { 0 };

    arrayGenerate(inputArray, 100);

    printf("Initial array, generated randomly:\n");
    arrayPrint(inputArray, 100);

    partQSort(inputArray, 100);

    printf("Sorted array.\nIn the top part there are numbers less than the first number of initial array.\n\
In the bottom part there are numbers greater than or equal to the first number of initial array.\n");

    arrayPrint(inputArray, 100);

    return 0;
}