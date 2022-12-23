#include <stdio.h>
#include <stdbool.h>
#include "postfixCalculator.h"

// Функция с тестами.
// Тестирует функцию на нескольких массивах, имитирующих пользовательский ввод.
// Возвращает true, если всё в порядке, и false в противном случае.
bool test(void) {
    CalculatorErrors testErrorCode = noCalculatorErrors;
    char testArray1[] = { '9', ' ', '6', ' ', '-', ' ', '3', ' ', '*', '\n'};
    char testArray2[] = { '\n' };
    char testArray3[] = { '9', ' ', '6', ' ', '-' };

    int result1 = postfixCalculator(testArray1, &testErrorCode);
    if (testErrorCode || result1 != 9) {
        return false;
    }

    postfixCalculator(testArray2, &testErrorCode);
    if (testErrorCode != errorInStack) {
        return false;
    }

    testErrorCode = noCalculatorErrors;

    postfixCalculator(testArray3, &testErrorCode);
    if (testErrorCode != invalidInput) {
        return false;
    }

    return true;
}

int main(void) {
    //Запуск тестов.
    if (!test()) {
        printf("Test failed.\n");
        return -1;
    }
    else {
        printf("*tests passed*\n\n");
    }

    CalculatorErrors errorCode = noCalculatorErrors;

    char arrayForInput[100];
    printf("Enter a space-separated expresson:\n");

    int counterOfTokens = 0;
    char token = ' ';

    // Помещение строки ввода в массив.
    while (counterOfTokens < 100) {
        token = getchar();

        arrayForInput[counterOfTokens] = token;
        counterOfTokens++;

        if (token == '\n') {
            break;
        }
    }

    // Если при достижении 100-го символа не был встречен перевод строки, то выражение признаётся некорректным.
    if (counterOfTokens == 100 && arrayForInput[99] != '\n') {
        printf("Too many symbols\n");
        return -1;
    }

    int result = postfixCalculator(arrayForInput, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    printf("Result: %d\n", result);

    return 0;
}