#pragma once

#include <stdbool.h>

// ���� ������ ��� �������� �������.
typedef enum BalanceErrorCode {
    noErrorsInBalance,
    errorInStack
} BalanceErrorCode;

// �������� ������� ������.
// �� ���� ��������� ��������� �� ����������� ������ � �� ��� ������.
// ���������� true, ���� � �������� �� � �������, � false � ��������� ������.
bool upgradedParenthesesBalance(char* string, BalanceErrorCode* errorCode);
