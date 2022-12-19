#pragma once

typedef enum CalculatorErrors {
    noCalculatorErrors,
    invalidInput,
    errorInStack
} CalculatorErrors;

// ����������� �����������.
// �� ���� ��������� ������ ��������� �� ��� ������. ��� ������� ��������� ��������� �� �������� ������.
// ���������� ��������� - ����� �����.
int postfixCalculator(CalculatorErrors* errorCode);