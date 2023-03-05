#pragma once

#include <stdlib.h>

// Коды ошибок.
typedef enum ShuntingYardErrors {
    noErrorsInYard,
    errorInStack,
    wrongExpression
}ShuntingYardErrors;

// Перевод выражения из инфиксной нотации в постфиксную.
// На вход принимает указатели на исходную строку и строку для результата, их размер и указатель на код ошибки.
void shuntingYard(char* inputArray, char* outputArray, size_t arraysSize, ShuntingYardErrors* errorCode);