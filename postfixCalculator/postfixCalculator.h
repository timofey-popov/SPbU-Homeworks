#pragma once

typedef enum CalculatorErrors {
    noCalculatorErrors,
    stackCreationError,
    popError,
    pushError,
    ivalidInput
} CalculatorErrors;

int postfixCalculator(CalculatorErrors* errorCode);