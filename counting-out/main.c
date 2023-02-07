#include "counting-out.h"
#include "tests.h"

#include <stdio.h>

// Вспомогательная функция. Полностью очищает поток ввода.
// Нужно использовать аккуратно, так как если в потоке ничего нет, функция будет ждать следующего ввода и очистит один симол этого ввода (или весь ввод?).
void customFlush(void) {
    int junk1 = scanf_s("%*[^\n]");
    char junk2 = getchar();
}

// Возвращает целое число, введённое пользователем. Если запись не удалась - печатает на экран просьбу повторить ввод.
int getPositiveInteger(void) {
    int valueToReturn = 0;
    
    int correctnessCheck = scanf_s("%d", &valueToReturn);

    while (!correctnessCheck || (valueToReturn < 1)) {
        customFlush();
        printf("Invalid input. Try again:\n");
        correctnessCheck = scanf_s("%d", &valueToReturn);
    }

    return valueToReturn;
}

int main(void) {
    if (!insideTests() || !testForCalculating()) {
        printf("Tests failed:\nInside test: %d\nMain test: %d\n\n", insideTests(), testForCalculating());
        return -1;
    }
    else {
        printf("*tests passed*\n\n");
    }

    CountingOutErrors errorCode = noErrors;

    printf("Enter n:\n");
    int n = getPositiveInteger();
    printf("Enter m:\n");
    int m = getPositiveInteger();

    int result = calculateSuitablePosition(n, m, &errorCode);
    if (errorCode) {
        printf("Error %d occured\n\n", errorCode);
        return errorCode;
    }

    printf("Result: take position %d\n\n", result);

    return 0;
}