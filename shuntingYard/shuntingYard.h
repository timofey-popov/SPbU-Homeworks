#pragma once

#include <stdlib.h>

// ���� ������.
typedef enum ShuntingYardErrors {
    noErrorsInYard,
    errorInStack,
    wrongExpression
}ShuntingYardErrors;

// ������� ��������� �� ��������� ������� � �����������.
// �� ���� ��������� ��������� �� �������� ������ � ������ ��� ����������, �� ������ � ��������� �� ��� ������.
void shuntingYard(char* inputArray, char* outputArray, size_t arraysSize, ShuntingYardErrors* errorCode);