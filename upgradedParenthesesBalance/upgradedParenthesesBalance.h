#pragma once

#include <stdbool.h>

typedef enum BalanceErrorCode {
    noErrorsInBalance,
    errorInStack
} BalanceErrorCode;

// Проверка баланса скобок.
// На вход принимает указатели на проверяемую строку и на код ошибки.
// Возвращает true, если с балансом всё в порядке, и false в противном случае.
bool upgradedParenthesesBalance(char* string, BalanceErrorCode* errorCode);
