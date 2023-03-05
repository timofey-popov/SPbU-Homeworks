#pragma once

// Коды ошибок калькулятора.
typedef enum CalculatorErrors {
    noCalculatorErrors,
    invalidInput,
    errorInStack
} CalculatorErrors;

// Постфиксный калькулятор.
// На вход принимает указатели на массив со вводом и на код ошибки.
// Возвращает результат - целое число.
int postfixCalculator(char* inputArray, CalculatorErrors* errorCode);
