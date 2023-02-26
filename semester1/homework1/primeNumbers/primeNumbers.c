#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

// Функция, которая распечатывает все простые числа до limit включительно.
// На вход принимает limit.
void printPrimeNumbers(int limit) {
    for (int i = 2; i < limit + 1; ++i) {
        bool counter = 0;

        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                counter++;
                break;
            }
        }

        if (!counter) {
            printf("\n%d", i);
        }
    }
}

// Функция обработки пользовательского ввода.
// Возвращает считанное число в место вызова.
int userInput(void) {
    int valueToReturn = 0;

    printf("Enter the limit\n(please, don't enter anything but numbers)\n");
    int correctnessCheck = scanf_s("%d", &valueToReturn);

    while (valueToReturn < 2 || !correctnessCheck) {
        printf("There's no such prime numbers. Enter another limit\n");
        scanf_s("%*[^\n]");
        correctnessCheck = scanf_s("%d", &valueToReturn);
    }

    return valueToReturn;
}

int main(void) {
    int limit = userInput();

    printPrimeNumbers(limit);

    return 0;
}