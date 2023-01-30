#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// Итеративная функция для вычисления i-того числа Фибоначчи.
// На вход принимает i.
unsigned long long iterativeFibonacciNumbers(int indexNumber) {
    if (indexNumber == 1) {
        return 0;
    }

    if (indexNumber == 2) {
        return 1;
    }
    
    unsigned long long prePreNumber = 0;
    unsigned long long preNumber = 1;
    unsigned long long valueToReturn = 1;

    for (int i = 0; i < indexNumber - 2; ++i) {
        valueToReturn = prePreNumber + preNumber;

        prePreNumber = preNumber;
        preNumber = valueToReturn;
    }

    return valueToReturn;
}

// Функция-тест. Сравнивает фактические значения, которые выдаёт функция, с эталонными.
bool test(void) {
    char referenceArray[10] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
    float delta = 0.001;

    for (int i = 0; i < 10; ++i) {
        if (iterativeFibonacciNumbers(i + 1) - referenceArray[i] > delta) {
            return false;
        }
    }

    return true;
}

int main(void) {
    if (!test()) {
        printf("Test failed.\n");
        return -1;
    } else {
        printf("*Test passed*\n");
    }

    int indexNumber = 0;

    printf("Enter the number of Fibonacci sequence element:\n");
    int isInputCorrect = scanf("%d", &indexNumber);
    scanf_s("%*[^\n]");

    while (isInputCorrect == 0 || indexNumber < 1) {
        scanf_s("%*[^\n]");
        printf("You've entered not a number or not a positive number. Please, try again.\n");
        printf("Enter the number of Fibonacci sequence element:\n");
        isInputCorrect = scanf("%d", &indexNumber);
    }
    scanf_s("%*[^\n]");

    long time1 = clock();

    printf("%d-th element of the Fibonacci sequence is %llu\n", indexNumber, iterativeFibonacciNumbers(indexNumber));
    printf("Time passed: %ld seconds\n", (clock() - time1) / CLOCKS_PER_SEC);

    return 0;
}