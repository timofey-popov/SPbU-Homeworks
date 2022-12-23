#pragma once

#include "../customStack/customStack.h"
#include <stdbool.h>

typedef enum BalanceErrorCode {
    noErrors,

} BalanceErrorCode;

bool upgradedParenthesesBalance(char* string, BalanceErrorCode errorCode);
