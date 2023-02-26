#pragma once

#include <stdbool.h>

// ���� ������:
// 0 - ��� ������.
// 1 - ������ ��������� ������.
// 2 - � �������� ��������� �� ������ ������� NULL.
// 3 - � ������ ��� �������� � ����� �������.
// 4 - � ������ ��� ���������.
typedef enum ErrorCodes {
    noErrors,
    memoryAllocationError,
    nullPointerReceived,
    noSuchNumberInList,
    emptyListReceived
} ErrorCodes;

// ��� ������, ���������� � ������. ���� ����� ��� �������� - ����� �����.
typedef int Value;

// ��� ��������� "���������� ������".
typedef struct LinkedList LinkedList;

// ������� ������.
// ���������� ��������� �� ��������� ������ ��� NULL, ���� ��������� ������.
// � ������ ������ ������ �� ��������, ������� ��� �� �����.
LinkedList* createLinkedList(ErrorCodes* errorCode);

// �������� ������� � ������ ������.
void pushToHead(Value value, LinkedList* list, ErrorCodes* errorCode);

// �������� ������� � ����� ������.
void pushToTail(Value value, LinkedList* list, ErrorCodes* errorCode);

// �������� ������� �� n-��� ����� � ������ (��������� �� 1).
void insertNthElement(Value value, int n, LinkedList* list, ErrorCodes* errorCode);

// �������� �������� ������� �������� � ������ � ������� ���� �������.
// ���������� ��������, ������� ������ � ���� ��������.
Value popFromHead(LinkedList* list, ErrorCodes* errorCode);

// �������� �������� ���������� �������� � ������ � ������� ���� �������.
// ���������� ��������, ������� ������ � ���� ��������.
Value popFromTail(LinkedList* list, ErrorCodes* errorCode);

// �������� �������� n-���� �������� � ������ (��������� �� 1) � ������� ���� �������.
// ���������� ��������, ������� ������ � ���� ��������.
Value popNthElement(LinkedList* list, int n, ErrorCodes* errorCode);

// �������� �������� n-���� �������� � ������ (��������� �� 1), �� ������ ���� �������.
// ���������� ��������, ������� ����� � ���� ��������.
Value getNthValue(LinkedList* list, int n, ErrorCodes* errorCode);

// ��������� ������ �� �������.
bool isEmpty(LinkedList* list, ErrorCodes* errorCode);

// ������� ��� �������� �� ������, �� �� ������� ������.
// ����� �� ��������� ��������� ��������.
void clearList(LinkedList* list, ErrorCodes* errorCode);

// ������� ������.
void deleteLinkedList(LinkedList* list, ErrorCodes* errorCode);
