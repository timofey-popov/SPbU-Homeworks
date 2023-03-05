#include "circularList.h"
#include "tests.h"

#include <stdio.h>

// ��������������� �������. ��������� ������� ����� �����.
// ����� ������������ ���������, ��� ��� ���� � ������ ������ ���, ������� ����� ����� ���������� ����� � ������� ���� ����� ����� ����� (��� ���� ����?).
void customFlush(void) {
    int junk1 = scanf_s("%*[^\n]");
    char junk2 = getchar();
}

// ���������� ����� �����, �������� �������������. ���� ������ �� ������� - �������� �� ����� ������� ��������� ����.
int getPositiveInteger(void) {
    int valueToReturn = 0;
    
    int correctnessCheck = scanf_s("%d", &valueToReturn);

    while (!correctnessCheck || (valueToReturn < 1)) {
        customFlush();
        printf("Invalid input. Try again:\n");
        correctnessCheck = scanf_s("%d", &valueToReturn);
    }

    return valueToReturn;
}

int main(void) {
    if (!testForCreateAndDeleteList() || !testForAddAndDeleteValue() || !testForCalculating()) {
        printf("Tests failed: %d, %d, %d\n\n", testForCreateAndDeleteList(), testForAddAndDeleteValue(), testForCalculating());
        return -1;
    }
    else {
        printf("*tests passed*\n\n");
    }

    ListErrors errorCode = noErrorsInList;

    printf("Enter the number of warriors:\n");
    int numberOfWarriors = getPositiveInteger();
    printf("Enter the pace of a counting-out:\n");
    int paceOfCountingOut = getPositiveInteger();

    int result = calculateSuitablePosition(numberOfWarriors, paceOfCountingOut, &errorCode);
    if (errorCode) {
        printf("Error %d occured\n\n", errorCode);
        return errorCode;
    }

    printf("Result: take position %d\n\n", result);

    return 0;
}