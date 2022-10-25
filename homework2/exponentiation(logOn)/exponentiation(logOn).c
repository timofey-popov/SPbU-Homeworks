#include <stdio.h>
#include <stdbool.h>

// Функция возведения в степень двоичным деревом.
// На вход принимает основание и показатель степени.
long double exponentLogOn(float base, int exponent) {
    if (exponent < 0)
        exponent = -exponent;

    if (exponent == 0)
        return 1;

    if (exponent % 2 == 1)
        return (base * exponentLogOn(base, exponent - 1));

    long double temporary = exponentLogOn(base, exponent / 2);
    return temporary * temporary;
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
    return;
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
    return;
}

// Функция-тест, проверяет совпадение эталонных и фактических значений, выдаваемых функцией.
bool testCorrectCases(void) {
    float delta = 0.01;

    return (exponentLogOn(5, 2) - 25 < delta && exponentLogOn(7, 3) - 343 < delta && exponentLogOn(-2, 3) + 8 < delta && exponentLogOn(-3, 2) - 9 < delta && exponentLogOn(-5, 0) - 1 < delta);
}

int main(void) {
    if (!testCorrectCases()) {
        printf("Test failed\n");
        return -1;
    }
    else
        printf("*Test passed*\n");

    float base = 0;
    int exponentNumber = 0;

    printf("DO NOT ENTER ANYTHING BUT NUMBERS\nEnter the base:\n");
    userInputForFloat(&base);

    printf("Enter the exponent:\n");
    userInputForInteger(&exponentNumber);

    if (exponentNumber >= 0)
        printf("The answer is %.2Lf\n", exponentLogOn(base, exponentNumber));

    else
        printf("The answer is 1/%.2Lf\n", exponentLogOn(base, exponentNumber));

    return 0;
}