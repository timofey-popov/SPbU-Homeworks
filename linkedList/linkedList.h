#pragma once

// ���� ������:
typedef enum ListErrors {
    noErrors,
    memoryAllocationError,
    gotNullPointer
} ListErrors;

typedef int Value;

// ��� "������"
typedef struct List List;

// ������� ������.
// ���������� ��������� �� ��������� ������ ��� NULL, ���� ������� �� �������.
// ���� ������� �� ������� - ������ �� ���������, ������ ������� �� �����.
List* createList(ListErrors* errorCode);

// �������� ������� � ������.
void addElement(Value value, List* list, ListErrors* errorCode);

// ������� ������� �� ������ (����� �� ��������).
void deleteElementByValue(Value value, List* list, ListErrors* errorCode);

// ����������� ���� ������.
void printList(List* list, ListErrors* errorCode);

// ������� ������.
void deleteList(List* list, ListErrors* errorCode);
