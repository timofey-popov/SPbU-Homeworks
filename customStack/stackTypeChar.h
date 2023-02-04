#pragma once

#include <stdbool.h>

// ���� ������:
// 0 - ��� ������.
// 1 - ������ ��������� ������.
// 2 - � �������� ��������� �� ������ ����� ������� NULL.
// 3 - � ����� ��� ���������.
typedef enum StackErrors {
    noErrors,
    memoryAllocationError,
    nullPointerReceived,
    noElemensInStack,
} StackErrors;

// ��� ���������� ��� �������� � ��������� �����.
// ���� ����� �������� - ������ ��� ������ � ���� �����.
typedef char Value;

// ����������� ��� ������ "����".
typedef struct Stack Stack;

// ������ ������ ����.
// �� ���� ��������� ��������� �� ���������� � ����� ������.
// ���������� ��������� �� ����, ���� �� ������ ���������,� ��������� ������ ���������� NULL.
// � ������ ������ ���� �� ��������, ������� ��� �� �����.
Stack* createStack(StackErrors* errorCode);

// ��������� ������� �� �������� �����.
// �� ���� ��������� ����������� ��������, ��������� �� ���� � ��������� �� ���������� � ����� ������.
void push(Value value, Stack* stack, StackErrors* errorCode);

// �������� ������� ������� ����� �� ������ ���.
Value get(Stack* stack, StackErrors* errorCode);

// ������� ������� � ������� ����� � ���������� ��������, ������� � �� ������.
// �� ���� ��������� ��������� �� ���� � ��������� �� ���������� � ����� ������.
Value pop(Stack* stack, StackErrors* errorCode);

// ������� ��� �������� �� �����, ������ �� �� ��������.
// �� ���� ��������� ��������� �� ���� � ��������� �� ���������� � ����� ������.
void clear(Stack* stack, StackErrors* errorCode);

// ���������� true, ���� ���� ����, � false � ��������� ������.
// ���� � �������� ��������� �� ���� ������� NULL, ���������� false � ������ ��� ������.
bool isEmpty(Stack* stack, StackErrors* errorCode);

// ������� ��������� ����.
void deleteStack(Stack* stack, StackErrors* errorCode);

// �������� ��� �������� � ����� ��� ����� �����, ������� �� ������.
// ���� �� ���� ������� NULL, �������� �������������� � ������� � ������ ��� ������.
void printStack(Stack* stack, StackErrors* errorCode);
