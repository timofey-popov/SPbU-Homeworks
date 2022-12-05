#pragma once

#include <stdbool.h>

// ���� ������:
// 
typedef enum ErrorCodes {
    noErrors,
    createListMemoryError,
    pushToHeadGotNullPointer,
    pushToHeadMemoryError,
    pushToTailGotNullPointer,
    pushToTailMemoryError,
    insertNthElementGotNullPointer,
    noSuchNumberInList,
    insertNthElementMemoryError,
    popFromHeadGotNullPointer,
    popFromHeadGotEmptyList,
    popFromTailGotNullPointer,
    popFromTailGotEmptyList,
    popNthElementGotNullPointer,
    getNthValueGotNullPointer,
    isEmptyGotNullPointer,
    clearListGotNullPointer,
    deleteListGotNullPointer
} ErrorCodes;

// ��� ������, ���������� � ������. ���� ����� ��� �������� - ����� �����.
typedef int Value;

// ��� ��������� "���������� ������".
typedef struct LinkedList LinkedList;

// ������� ������.
// ���������� ��������� �� ��������� ������.
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