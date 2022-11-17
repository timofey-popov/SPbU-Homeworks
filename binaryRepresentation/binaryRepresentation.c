#include <stdio.h>
#include <locale.h>

#define NUMBER_OF_DIGITS 8

//Функция генерации двоичного представленмя числа, записанного cлева направо в массиве.
void generateBinary(int decimal, int* arrayForBinary) {
    int decimalCopy = decimal;
    int buffer[NUMBER_OF_DIGITS] = { 0 };

    for (int i = NUMBER_OF_DIGITS; i >= 0; --i) {
        buffer[i] = decimalCopy % 2;
        decimalCopy = decimalCopy / 2;
    }

    if (decimal >= 0) {
        for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
            arrayForBinary[i] = buffer[i];
        }
    } else {
        int bufferForAdditionalCode[NUMBER_OF_DIGITS] = { 0 };
        createAdditionalCode(buffer, bufferForAdditionalCode)
    }
}

int carryOut(int firstNumber, int secondNumber) {
    return firstNumber && secondNumber;
}

void addBinary(int* firstSummand, int* secondSummand, int* binaryResult) {
    int carryOutValue = 0;

    for (int i = NUMBER_OF_DIGITS - 1; i >= 0; --i) {
        binaryResult [i] = firstSummand[i] ^ secondSummand[i] ^ carryOutValue;

        

    }
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

    int binFirstNumber[NUMBER_OF_DIGITS] = { 0 };
    int binSecondNumber[NUMBER_OF_DIGITS] = { 0 };

    printf("Введите первое число (от -128 до 128):\n");
    inputInteger(&firstNumber, -128, 128);

    printf("Введите второе число (от -127 до 127):\n");
    inputInteger(&secondNumber, -127, 127);

    printf("Первое введённое число: %d\n", firstNumber);
    printf("Второе введённое число: %d\n", secondNumber);

    generateBinary(firstNumber, binFirstNumber);

    printf("Двоичное представление %d это ", firstNumber);
    printBinary(binFirstNumber);

    return 0;
}