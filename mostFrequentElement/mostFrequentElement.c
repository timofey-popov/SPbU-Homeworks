#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int mostFrequentElement(int* arrayToOperate, size_t arraySize) {
    int counter = 1;
    int maximumCounter = 1;
    int frequentElement = 0;

    for (size_t i = 1; i < arraySize; ++i) {
        if (arrayToOperate[i] == arrayToOperate[i - 1])
            counter++;
        else
            counter = 1;
        
        if (counter > maximumCounter) {
            maximumCounter = counter;
            frequentElement = arrayToOperate[i];
        }
    }

    return frequentElement;
}

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;

    return x - y;
}

bool test(void) {

}

int main(void) {
    int arrayToOperate[] = { 1, 5, 5, 6, 2, 3, 4, 7, 5, 1, 2, 3, 1, 1};
    size_t sizeOfArray = sizeof(arrayToOperate) / sizeof(int);

    qsort(arrayToOperate, sizeOfArray, sizeof(int),compare);

    for (size_t i = 0; i < sizeOfArray; ++i) {
        printf("%d ", arrayToOperate[i]);
    }
    printf("\n");

    printf("%d\n", mostFrequentElement(arrayToOperate, sizeOfArray));

    return 0;
}