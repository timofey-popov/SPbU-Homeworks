#pragma once

#include <stdbool.h>

// ���� ������:
// 0 - ��� ������.
// 1 - ������ ��������� ������.
// 2 - � �������� ��������� �� ������ ����� ������� NULL.
// 3 - � ����� ��� ���������.
typedef enum ErrorCodes {
    noErrors,
    memoryAllocationError,
    nullPointerReceived,
    noElemensInStack,
} ErrorCodes;

// ��� ���������� ��� �������� � ��������� �����.
// ���� ����� �������� - ������ ��� ������ � ���� �����.
typedef int Value;

// ����������� ��� ������ "����".
typedef struct Stack Stack;

// ������ ������ ����.
// �� ���� ��������� ��������� �� ���������� � ����� ������.
// ���������� ��������� �� ����, ���� �� ������ ���������,� ��������� ������ ���������� NULL � ������ ��� ������.
Stack* createStack(ErrorCodes* errorCode);

// ��������� ������� �� �������� �����.
// �� ���� ��������� ����������� ��������, ��������� �� ���� � ��������� �� ���������� � ����� ������.
void push(Value value, Stack* stack, ErrorCodes* errorCode);

// ������� ������� � ������� ����� � ���������� ��������, ������� � ��� ������.
// �� ���� ��������� ��������� �� ���� � ��������� �� ���������� � ����� ������.
Value pop(Stack* stack, ErrorCodes* errorCode);

// ������� ��� �������� �� �����, ������ �� �� ��������.
// �� ���� ��������� ��������� �� ���� � ��������� �� ���������� � ����� ������.
void clear(Stack* stack, ErrorCodes* errorCode);

// ���������� true, ���� ���� ����, � false � ��������� ������.
// ���� � �������� ��������� �� ���� ������� NULL, ���������� false � ������ ��� ������.
bool isEmpty(Stack* stack, ErrorCodes* errorCode);

// ������� ��������� ����.
void deleteStack(Stack* stack, ErrorCodes* errorCode);

// �������� ��� �������� � ����� ��� ����� �����, ������� �� ������.
// ���� �� ���� ������� NULL, �������� �������������� � ������� � ������ ��� ������.
void printStack(Stack* stack, ErrorCodes* errorCode);
