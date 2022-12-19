#pragma once

typedef enum CalculatorErrors {
    noCalculatorErrors,
    invalidInput,
    errorInStack
} CalculatorErrors;

// Постфиксный калькулятор.
// На вход принимает только указатель на код ошибки. При запуске считывает выражение из входного потока.
// Возвращает результат - целое число.
int postfixCalculator(CalculatorErrors* errorCode);