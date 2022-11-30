#include <stdio.h>

#define NUBER_OF_DIGITS 32

int integerInput(void) {
    int valueToReturn = 0;

    int correctnessCheck = scanf("%d", &valueToReturn);
    while (!correctnessCheck) {
        printf("Wrong input, try again.\n");
        correctnessCheck = scanf("%d", &valueToReturn);
    }

    return valueToReturn;
}

void createBinary(int* arrayForBinary) {
    for (int i = 0; i < NUBER_OF_DIGITS; ++i) {

    }
}

int main(void) {
    printf("Enter the first number:\n");
    int firstDecimal = integerInput();

    printf("Enter the second number:\n");
    int secondDecimal = integerInput();

    int firstBinary[NUBER_OF_DIGITS] = { 0 };
    int secondBinary[NUBER_OF_DIGITS] = { 0 };



    return 0;
}