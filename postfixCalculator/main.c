#include <stdio.h>
#include "postfixCalculator.h"

int main(void) {
    CalculatorErrors errorCode = noCalculatorErrors;
    printf("Result: %d\n", postfixCalculator(&errorCode));

    return 0;
}