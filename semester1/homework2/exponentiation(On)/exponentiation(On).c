﻿#include <stdio.h>
#include <stdbool.h>

// Функция возведения в степень простым умножением основания n раз.
// На вход принимает основание и показатель степени.
long double exponentOn(float base, int exponent) {
    int exponentCopy = exponent;
    
    if (exponentCopy < 0) {
        exponentCopy = -exponentCopy;
    }

    if (exponentCopy == 0) {
        return 1;
    }

    long double valueToReturn = base;

    for (int i = 0; i < exponentCopy - 1; ++i) {
        valueToReturn = valueToReturn * base;
    }
    

    return exponent > 0 ? valueToReturn : 1 / valueToReturn;
}

// Записывает введённое с клавиатуры число с плавающей запятой по переданному в аргумент адресу.
void userInputForFloat(float* whereToRecord) {
    int floatInputCorrectnessCheck = scanf_s("%f", whereToRecord);

    while (!floatInputCorrectnessCheck) {
        scanf_s("%*[^\n]");
        printf("You've entered NOT a number. Try again:\n");
        floatInputCorrectnessCheck = scanf("%f", whereToRecord);
    }

    scanf_s("%*[^\n]");
}

// Записывает введённое с клавиатуры целое число по переданному в аргумент адресу.
void userInputForInteger(int* whereToRecord) {
    int intInputCorrectnessCheck = scanf_s("%d", whereToRecord);

    while (!intInputCorrectnessCheck) {
        scanf_s("%*[^\n]");
        printf("You've entered NOT a number. Try again:\n");
        intInputCorrectnessCheck = scanf("%d", whereToRecord);
    }

    scanf_s("%*[^\n]");
}

// Функция-тест, проверяет совпадение эталонных и фактических значений, выдаваемых функцией.
bool testCorrectCases(void) {
    float delta = 0.01;

    return (exponentOn(5, 2) - 25 < delta && exponentOn(7, 3) - 343 < delta && exponentOn(-2, 3) + 8 < delta && exponentOn(-3, 2) - 9 < delta && exponentOn(-5, 0) - 1 < delta);
}

int main(void) {
    if (!testCorrectCases()) {
        printf("Test failed\n");
        return -1;
    } else {
        printf("*Test passed*\n");
    }

    float base = 0;
    int exponentNumber = 0;

    printf("DO NOT ENTER ANYTHING BUT NUMBERS\nEnter the base:\n");
    userInputForFloat(&base);

    printf("Enter the exponent:\n");
    userInputForInteger(&exponentNumber);

    printf("The answer is %.2Lf\n", exponentOn(base, exponentNumber));

    return 0;
}
