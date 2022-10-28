#include <stdio.h>
#include <stdbool.h>

int partition(int* arrayToSort, int leftElementNumber, int rightElementNumber) {
    int pivot = arrayToSort[rightElementNumber]; //3
    
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

void quickSort(int* arrayToSort, int leftElementNumber, int rightElementNumber) {
    if (leftElementNumber < rightElementNumber) {
        int separator = partition(arrayToSort, leftElementNumber, rightElementNumber);
        quickSort(arrayToSort, leftElementNumber, separator - 1);
        quickSort(arrayToSort, separator + 1, rightElementNumber);
    }
}

bool test(void) {

}

int main(void) {
    int testArray[] = { 5, 2, 2, 5, 3, 4, 6, 1, 2, 1 };
    size_t sizeOfArray = sizeof(testArray) / sizeof(int);
    printf("%zu", sizeOfArray);

    quickSort(testArray, 0, sizeOfArray - 1);

    for (int i = 0; i < sizeOfArray; ++i) {
        printf("%d, ", testArray[i]);
    }

    return 0;
}