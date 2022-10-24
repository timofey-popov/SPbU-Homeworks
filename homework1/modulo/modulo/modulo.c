#include <stdio.h>

// Функция получения частного и остатка.
// На вход принимает делимое, делитель, адрес переменной с частным, адрес переменной с остатком.
void modulo(int divident, int divider, int* quotient, int* reminder)
{
    int x = divident;
    int y = divider;

    if (x >= 0 && y > 0) {
        while (x >= y) {
            y += divider;
            (*quotient)++;
        }

        *reminder = divident - (divider * (*quotient));
        return;
    }

    if (x >= 0 && y < 0) {
        modulo(divident, -divider, quotient, reminder);
        *quotient = -(*quotient);
        return;
    }

    if (x < 0 && y > 0) {
        int i = 0;
        while (divider * (-i) > divident)
            ++i;

        *quotient = (-i);
        *reminder = divident - (divider * (-i));
        return;
    }

    if (x < 0 && y < 0) {
        modulo(divident, -divider, quotient, reminder);
        *quotient = -(*quotient);
        return;
    }
}

// Функция для ввода чисел пользователем.
// На вход принимает адрес для записи числа.
void userInput(int* digitForRecord) {

    int correctnessCheck = scanf_s("%d", digitForRecord);

    while (!correctnessCheck) {
        scanf_s("%*[^\n]");

        printf("Invalid input. Try again:\n");
        correctnessCheck = scanf_s("%d", digitForRecord);
    }

    return;
}

int main(void) {
    int quotient = 0;
    int reminder = 0;

    int divident = 0;
    int divider = 0;

    printf("Enter a divident:\n");
    userInput(&divident);
    scanf_s("%*[^\n]");

    printf("Enter a divider:\n");
    userInput(&divider);

    if (!divider) {
        printf("\nCan't divide by zero.\n");
        return 0;
    }

    modulo(divident, divider, &quotient, &reminder);

    printf("\n%d : %d = %d, reminder %d\n", divident, divider, quotient, reminder);

    return 0;
}