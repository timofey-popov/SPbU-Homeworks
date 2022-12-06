#pragma once

#include <stdbool.h>

// ���� ������:
// 0 - ��� ������.
// 1 - ������ ��������� ������ ��� ����� ���� (createStack).
// 2 - � �������� ��������� �� ������ ����� ������� NULL (push).
// 3 - ������ ��������� ������ ��� ����� ������� ����� (push).
// 4 - � �������� ��������� �� ������ ����� ������� NULL (pop).
// 5 - � ����� ��� ���������� ��� pop (pop).
// 6 - � �������� ��������� �� ������ ����� ������� NULL (clear).
// 7 - � �������� ��������� �� ������ ����� ������� NULL (isEmpty).
// 8 - � �������� ��������� �� ������ ����� ������� NULL (deleteStack).
// 9 - � �������� ��������� �� ������ ����� ������� NULL (printStack).
typedef enum ErrorCodes {
    noErrors,
    createStackMemoryError,
    pushGotNullPointer,
    pushMemoryError,
    popGotNullPointer,
    popStackHasNoElemens,
    clearGotNullPointer,
    isEmptyGotNullPointer,
    deleteStackGotNullPointer,
    printStackGotNullPointer,
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

// ������� ������� � ������� ����� � ���������� ��������, ������� � �� ������.
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
