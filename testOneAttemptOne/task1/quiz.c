#include <stdio.h>
#include <stdbool.h>

unsigned long long fibonacciNumbersAdder(unsigned long long upperLimit) {
    unsigned long long prePreNumber = 0;
    unsigned long long preNumber = 1;
    unsigned long long currentNumber = 1;

    unsigned long long sum = 0;

    while (currentNumber <= upperLimit) {
        currentNumber = prePreNumber + preNumber;

        prePreNumber = preNumber;
        preNumber = currentNumber;

        if (currentNumber % 2 == 0 && currentNumber <= upperLimit)
            sum += currentNumber;
    }

    return sum;
}

bool test1(void) {
    return !(fibonacciNumbersAdder(2) == 2 && fibonacciNumbersAdder(15) == 10 && fibonacciNumbersAdder(1000000) == 1089154);
}

int main(void)
{
    if (test1()) {
        printf("Test failed.");
        return -1;
    }

    unsigned long long maximumValueOfFibonacciNumber = 1000000;

    unsigned long long result = fibonacciNumbersAdder(maximumValueOfFibonacciNumber);
    printf("Sum of even Fibo numbers from 0 to %llu is %llu\n", maximumValueOfFibonacciNumber, result);

    return 0;
}