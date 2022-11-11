#include <stdio.h>
#include <locale.h>

// Функция генерации двоичного представленмя числа, перевёрнутого задом наперёд.
// Потом этот массив будет перевёрнут и число будет каким и должно быть.

//void binGenerator(int decimal, int* arrayForBinary)
//{
//    int decimalCopy = decimal;
//
//    int i = 0;
//    while (decimalCopy)
//    {
//        arrayForBinary[i] = decimalCopy % 2;
//        decimalCopy = decimalCopy / 2;
//        ++i;
//    }
//
//}

void arrayPrint(int* arrayToPrint, int printingArraySize)
{
    for (int i = 1; i < printingArraySize + 1; ++i)
    {
        printf("%7d", arrayToPrint[i - 1]);
        if (i % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n\n");
}

void integerUserInput(int* valueToWrite, int leftLimit, int rightLimit) {
    int isInputCorrect = scanf("%d", valueToWrite);
    printf("%d\n", isInputCorrect);
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

    int binFirstNumber[8] = { 0 };
    int binSecondNumber[8] = { 0 };

    printf("Введите первое число (от -128 до 128):\n");
    integerUserInput(&firstNumber, -128, 128);

    printf("Введите второе число (от -127 до 127):\n");
    integerUserInput(&secondNumber, -127, 127);

    printf("%d\n", firstNumber);
    printf("%d\n", secondNumber);

    return 0;
}