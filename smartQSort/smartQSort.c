#include <stdio.h>
#include <stdbool.h>

int getSeparator(int* arrayToSort, int leftElementNumber, int rightElementNumber) {

}

void partQSort(int* arrayToSort, int leftElementNumber, int rightElementNumber) {
    if (leftElementNumber < rightElementNumber) {
        int separator = getSeparator(arrayToSort, leftElementNumber, rightElementNumber);
        partQSort(arrayToSort, leftElementNumber, separator);
        partQSort(arrayToSort, separator + 1, rightElementNumber);
    }
}

bool test(void) {

}

int main(void) {


    return 0;
}