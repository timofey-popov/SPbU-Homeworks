#pragma once

#include <stdbool.h>

// ���� ������.
typedef enum CountingOutErrors {
    noErrors,
    memoryAllocationError,
    programDoesNotWork
} CountingOutErrors;

// �������, ����������� ����������������� �������������� ������� ���������. ���� ��� ������� ���������� false - ��������� �������� �����������.
// ������������� ��������� ����� ������� ������.
bool insideTests(void);

// ���������� ����� k ������� ���������� ������ �����, ���� ������ n � ������� ������� m-����.
int calculateSuitablePosition(int n, int m, CountingOutErrors* errorCode);
