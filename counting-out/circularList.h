#pragma once

#include <stdbool.h>

// ���� ������.
typedef enum ListErrors {
    noErrors,
    memoryAllocationError,
    gotNullPointer
} ListErrors;

// ��� "����������� ������".
typedef struct CircularList CircularList;

// ������� ����� ������. ���� ��� ������ �� ���� - ������ �� ��� ������.
CircularList* createList(ListErrors* errorCode);

// �������� ��������� � ������.
void addToList(int value, CircularList* list, ListErrors* errorCode);

// ������� �������� �� ������.
// ����� ������� ������ ��������, ����������� � ��������.
// ���� ������ �������� ��� - ������ �� ����� �������, ������ �� ���������.
void deleteFromList(int value, CircularList* list, ListErrors* errorCode);

// ���������� ����� k ������� ���������� ������ �����, ���� ������ n � ������� ������� m-����.
int calculateSuitablePosition(int n, int m, CircularList* list, ListErrors* errorCode);

// ������� ������.
void deleteList(CircularList* list, ListErrors* errorCode);