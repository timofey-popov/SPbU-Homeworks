#pragma once

// ���� ������ ������������.
typedef enum CalculatorErrors {
    noCalculatorErrors,
    invalidInput,
    errorInStack
} CalculatorErrors;

// ����������� �����������.
// �� ���� ��������� ��������� �� ������ �� ������ � �� ��� ������.
// ���������� ��������� - ����� �����.
int postfixCalculator(char* inputArray, CalculatorErrors* errorCode);
