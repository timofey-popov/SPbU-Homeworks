#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#include "binaryRepresentation.h"
#include "tests.h"

int integerInput(void) {
    int valueToReturn = 0;

    int correctnessCheck = scanf_s("%d", &valueToReturn);
    while (!correctnessCheck) {
        printf("Wrong input, try again.\n");
        correctnessCheck = scanf_s("%d", &valueToReturn);
    }

    return valueToReturn;
}

void createBinary(int decimal, int* arrayForBinary) {
    int decimalCopy = decimal;

    for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
        arrayForBinary[i] = decimalCopy & 1;
        decimalCopy = decimalCopy >> 1;
    }
}

void printBinary(int* binary) {
    for (int i = NUMBER_OF_DIGITS - 1; i >= 0; --i) {
        printf("%d", binary[i]);
    }

    printf("\n");
}

void addBinary(int* firstSummand, int* secondSummand, int* result) {
    int carryOut = 0;

    for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
        int sum = firstSummand[i] + secondSummand[i] + carryOut;
        result[i] = sum % 2;
        carryOut = sum / 2;
    }
}

int createDecimal(int* binary) {
    int valueToReturn = 0;

    for (int i = NUMBER_OF_DIGITS - 1; i > 0; --i) {
        valueToReturn += binary[i];
        valueToReturn = valueToReturn << 1;
    }

    valueToReturn += binary[0];

    return valueToReturn;
}

int main(void) {
    if (!testForCreateBinary() || !testForCreateDecimal() || !testForAddBinary()) {
        printf("Tests failed.\n");
        return -1;
    }
    else {
        printf("*tests passed*\n\n");
    }

    setlocale(LC_ALL, "");

    printf("Введите первое число:\n");
    int firstDecimal = integerInput();

    printf("Введите второе число:\n");
    int secondDecimal = integerInput();

    int firstBinary[NUMBER_OF_DIGITS] = { 0 };
    int secondBinary[NUMBER_OF_DIGITS] = { 0 };

    createBinary(firstDecimal, firstBinary);
    createBinary(secondDecimal, secondBinary);

    printf("\nПервое число в двоичном представлении:\n");
    printBinary(firstBinary);
    printf("Второе число в двоичном представлении:\n");
    printBinary(secondBinary);

    int binarySum[NUMBER_OF_DIGITS] = { 0 };

    addBinary(firstBinary, secondBinary, binarySum);

    printf("\nИх сумма в двоичном представлении:\n");
    printBinary(binarySum);

    printf("\nИх сумма в десятичном представлении:\n");
    printf("%d\n", createDecimal(binarySum));

    return 0;
}