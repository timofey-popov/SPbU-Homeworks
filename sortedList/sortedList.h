#pragma once

// ���� ������.
typedef enum ListErrors {
    noErrors,
    memoryAllocationError,
    gotNullPointer
} ListErrors;

// ��� "������������� ������".
typedef struct SortedList SortedList;

// ������� ����� ������. ���� ��� ������ �� ���� - ���� �� ��� ������.
SortedList* createList(ListErrors* errorCode);

// �������� ��������� � ������.
void addToList(int value, SortedList* list, ListErrors* errorCode);

// ������� �������� �� ������.
// ����� ������� ������ ��������, ����������� � ��������.
// ���� ������ �������� ��� - ������ �� ����� �������, ������ �� ���������.
void deleteFromList(int value, SortedList* list, ListErrors* errorCode);

// ����������� ���� ������. �������� ����� � �������.
void printWholeList(SortedList* list, ListErrors* errorCode);

// ������� ������������� ������.
void deleteList(SortedList* list, ListErrors* errorCode);
