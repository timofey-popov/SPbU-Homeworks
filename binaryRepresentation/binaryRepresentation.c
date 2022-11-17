#include <stdio.h>
#include <locale.h>

#define NUMBER_OF_DIGITS 8

int exponentOfTwo(int exponent) {
    if (exponent == 0) {
        return 1;
    }

    if (exponent % 2 == 1) {
        return (2 * exponentOfTwo(exponent - 1));
    }

    int temporary = exponentOfTwo(exponent / 2);
    return temporary * temporary;
}

void createAdditionalCode(int* binarySubtrahend, int* binaryResult) {
    int binaryMinuend[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0 };
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

//Функция генерации двоичного представленмя числа, записанного cлева направо в массиве.
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

void generateDecimal(int* binary, int* variableForDecimal) {
    int result = 0;

    for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
        result += binary[i] * exponentOfTwo(NUMBER_OF_DIGITS - 1 - i);
    }

    if (result > 128) {
        *variableForDecimal = result - 256;
        return;
    }

    *variableForDecimal = result;
}

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

void printBinary(int* numberToPrint) {
    for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
        printf("%d", numberToPrint[i]);
    }

    printf("\n");
}

void printArray(int* arrayToPrint, int printingArraySize) {
    for (int i = 1; i < printingArraySize + 1; ++i) {
        printf("%7d", arrayToPrint[i - 1]);
        if (i % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

void inputInteger(int* valueToWrite, int leftLimit, int rightLimit) {
    int isInputCorrect = scanf("%d", valueToWrite);

    while (!isInputCorrect || *valueToWrite > rightLimit || *valueToWrite < leftLimit) {
        printf("Некорректный ввод, попробуйте ещё раз:\n");
        scanf("%*[^\n]");
        isInputCorrect = scanf("%d", valueToWrite);
    }
}

int main(void)
{
    // Русский язык, переменные для двух вводимых чисел, массивы для двоичных представлений этих чисел.
    setlocale(LC_ALL, "");

    int firstNumber = 0;
    int secondNumber = 0;

    int firstBinNumber[NUMBER_OF_DIGITS] = { 0 };
    int secondBinNumber[NUMBER_OF_DIGITS] = { 0 };

    printf("Введите первое число (от -127 до 128):\n");
    inputInteger(&firstNumber, -127, 128);

    printf("Введите второе число (от -127 до 128):\n");
    inputInteger(&secondNumber, -127, 128);

    printf("Первое введённое число: %d\n", firstNumber);
    printf("Второе введённое число: %d\n", secondNumber);

    generateBinary(firstNumber, firstBinNumber);
    generateBinary(secondNumber, secondBinNumber);

    printf("Двоичное представление %d это ", firstNumber);
    printBinary(firstBinNumber);
    printf("Двоичное представление %d это ", secondNumber);
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