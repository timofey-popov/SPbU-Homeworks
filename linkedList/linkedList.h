#pragma once

#include <stdbool.h>

// ���� ������:
typedef enum ListErrors {
    noErrors,
    memoryAllocationError,
    gotNullPointer, 
    gotInvalidNumber,
    noSuchElementInList
} ListErrors;

// ��� ������, �������� � ������.
typedef int Value;

// ��� "������".
typedef struct List List;

// ������� ������.
// ���������� ��������� �� ��������� ������ ��� NULL, ���� ������� �� �������.
// ���� ������� �� ������� - ������ �� ���������, ������ ������� �� �����.
List* createList(ListErrors* errorCode);

// �������� ������� � ������.
void addElement(Value value, List* list, ListErrors* errorCode);

// ������� ������� �� ������ (����� �� ��������).
void deleteElementByValue(Value value, List* list, ListErrors* errorCode);

// �������� ���������� ��������� � ������.
int getListLength(List* list, ListErrors* errorCode);

// �������� n-��� �������� ������ (��������� �� 1), �� ������ ���.
Value getNthValue(List* list, int number, ListErrors* errorCode);

// �������� n-��� �������� ������ (��������� �� 1) � ������� n-��� �������.
Value popNthElement(List* list, int number, ListErrors* errorCode);

// ���������� true, ���� ������ ����, � false � ��������� ������.
bool isEmpty(List* list, ListErrors* errorCode);

// ����������� ���� ������.
void printList(List* list, ListErrors* errorCode);

// ������� ������.
void deleteList(List* list, ListErrors* errorCode);
