#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "tests.h"

#define NUMBER_OF_DIGITS 8

// Вспомогательная функция.
// Возводит двойку в степень "аргумент" и возвращает результат как целое число.
// Некорректна на отрицательных степенях.
int positiveExponentOfTwo(int exponent) {
    if (exponent == 0) {
        return 1;
    }

    if (exponent % 2 == 1) {
        return (2 * positiveExponentOfTwo(exponent - 1));
    }

    int temporary = positiveExponentOfTwo(exponent / 2);
    return temporary * temporary;
}

// Функция генерации допольнительного двоичного кода для двоичного числа с NUMBER_OF_DIGITS разрядами.
// На вход принимает указатель на двоичное число и указатель на массив-число, в который нужно положить результат.
void createAdditionalCode(int* binarySubtrahend, int* binaryResult) {
    int binaryMinuend[NUMBER_OF_DIGITS + 1] = { 0 };
    binaryMinuend[0] = 1;
    int carryOutValue = 0;

    for (int i = NUMBER_OF_DIGITS - 1; i >= 0; --i) {
        binaryResult[i] = ((binaryMinuend[i + 1] ^ binarySubtrahend[i]) ^ carryOutValue);

        switch (carryOutValue) {
        case 0:
            carryOutValue = !binaryMinuend[i + 1] && binarySubtrahend[i];
            break;
        case 1:
            carryOutValue = !binaryMinuend[i + 1] || binarySubtrahend[i];
            break;
        }
    }
}

// Функция генерации двоичного представленмя числа по десятичному.
// Записывает сгенерированное двоичное число в указанный в аргументах функции массив cлева направо.
void generateBinary(int decimal, int* arrayForBinary) {
    int decimalCopy = decimal >= 0 ? decimal : -decimal;
    int buffer[NUMBER_OF_DIGITS] = { 0 };

    for (int i = NUMBER_OF_DIGITS - 1; i >= 0; --i) {
        buffer[i] = decimalCopy % 2;
        decimalCopy = decimalCopy / 2;
    }

    if (decimal >= 0) {
        for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
            arrayForBinary[i] = buffer[i];
        }
    } else {
        int bufferForAdditionalCode[NUMBER_OF_DIGITS] = { 0 };
        createAdditionalCode(buffer, bufferForAdditionalCode);

        for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
            arrayForBinary[i] = bufferForAdditionalCode[i];
        }
    }
}

// Функция, которая строит десятичное число по данному двоичному.
// На вход принимает массив с двоичным числом и переменную, куда нужно положить десятичный результат.
// Важно: функция корректно работает только для чисел от -(2**(NUMBER_OF_DIGITS - 1) - 1) до 2**(NUMBER_OF_DIGITS - 1) в дополнительном двоичном коде.
// Она вызывается в программе всего один раз, от результата функции addBinary, которая, в свою очередь, никак не может выдать неподходящее число.
void generateDecimal(int* binary, int* variableForDecimal) {
    int result = 0;

    for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
        result += binary[i] * positiveExponentOfTwo(NUMBER_OF_DIGITS - 1 - i);
    }

    if (result > positiveExponentOfTwo(NUMBER_OF_DIGITS - 1)) {
        *variableForDecimal = result - positiveExponentOfTwo(NUMBER_OF_DIGITS);
        return;
    }

    *variableForDecimal = result;
}

// Функция побитового сложения чисел в дополнительном двоичном коде.
// На вход принимает три указателя на массивы: первое и второе двоичное слагаемое и массив для результата.
// Если в процессе сложения возникает "лишний" бит переноса - он никак не учитывается. Это должно учитываться ДО передачи чисел в функцию.
// Конкретно в этой программе это контролирует функция для пользовательского ввода.
void addBinary(int* firstSummand, int* secondSummand, int* binaryResult) {
    int carryOutValue = 0;

    for (int i = NUMBER_OF_DIGITS - 1; i >= 0; --i) {
        binaryResult [i] = firstSummand[i] ^ secondSummand[i] ^ carryOutValue;

        switch (carryOutValue) {
        case 0:
            carryOutValue = firstSummand[i] && secondSummand[i];
            break;
        case 1:
            carryOutValue = firstSummand[i] || secondSummand[i];
            break;
        }
    }
}

// Функция, которая печатает на экран NUMBER_OF_DIGITS разрядов указанного двоичного числа.
void printBinary(int* numberToPrint) {
    for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
        printf("%d", numberToPrint[i]);
    }

    printf("\n");
}

// Функция пользовательского ввода для целых чисел.
// На вход принимает указатель на переменную для записи и левое и правое ограничение для вводимого числа.
void inputInteger(int* valueToWrite, int leftLimit, int rightLimit) {
    int isInputCorrect = scanf("%d", valueToWrite);

    while (!isInputCorrect || *valueToWrite > rightLimit || *valueToWrite < leftLimit) {
        printf("Некорректный ввод, попробуйте ещё раз:\n");
        scanf("%*[^\n]");
        isInputCorrect = scanf("%d", valueToWrite);
    }
}

// Функция-тест. Запускает тесты из tests.c для этой программы.
// Возвращает true, если все тесты прошли успешно, и false в противном случае.
bool test(void) {
    return testForPositiveExponent() && testForCreateAdditionalCode() && testForGenerateBinary() && testForGenerateDecimal && testForAddBinaries;
}

int main(void)
{
    if (!test()) {
        printf("Tests failed.\n");
        return -1;
    } else {
        printf("*Tests passed*\n\n");
    }

    // Русский язык, переменные для двух вводимых чисел, массивы для двоичных представлений этих чисел.
    setlocale(LC_ALL, "");

    int firstNumber = 0;
    int secondNumber = 0;

    int firstBinNumber[NUMBER_OF_DIGITS] = { 0 };
    int secondBinNumber[NUMBER_OF_DIGITS] = { 0 };

    int roughLimit = positiveExponentOfTwo(NUMBER_OF_DIGITS - 2);

    printf("Введите первое число (от %d до %d):\n", -roughLimit, roughLimit);
    inputInteger(&firstNumber, -roughLimit, roughLimit);

    printf("Введите второе число (от %d до %d):\n", -roughLimit + 1, roughLimit);
    inputInteger(&secondNumber, -roughLimit + 1, roughLimit);

    printf("\nПервое введённое число: %4d\n", firstNumber);
    printf("Второе введённое число: %4d\n", secondNumber);

    generateBinary(firstNumber, firstBinNumber);
    generateBinary(secondNumber, secondBinNumber);

    printf("Двоичное представление %4d это ", firstNumber);
    printBinary(firstBinNumber);
    printf("Двоичное представление %4d это ", secondNumber);
    printBinary(secondBinNumber);

    int binAdditionResult[NUMBER_OF_DIGITS] = { 0 };
    addBinary(firstBinNumber, secondBinNumber, binAdditionResult);

    printf("Результат их сложения в дополнительном двоичном коде: ");
    printBinary(binAdditionResult);

    int decimalAdditionResult = 0;
    generateDecimal(binAdditionResult, &decimalAdditionResult);

    printf("Результат их сложения в десятичном представлении: ");
    printf("%d\n", decimalAdditionResult);

    return 0;
}
