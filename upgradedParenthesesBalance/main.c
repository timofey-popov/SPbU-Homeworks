#include "upgradedParenthesesBalance.h"
#include <stdio.h>

int main(void) {
    BalanceErrorCode errorCode = noErrorsInBalance;
    char* string = "[({(){}[]})]";

    bool result = upgradedParenthesesBalance(string, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    printf(result ? "Result: true\n" : "Result: false\n");

    return 0;
}
