#include <stdio.h>
#include <stdbool.h>
#include "postfixCalculator.h"

bool test(void) {

}

int main(void) {
    CalculatorErrors errorCode = noCalculatorErrors;

    printf("Enter a space-separated expresson:\n");

    int result = postfixCalculator(&errorCode);
    if (errorCode) {
        return errorCode;
    }

    printf("Result: %d\n", result);

    return 0;
}