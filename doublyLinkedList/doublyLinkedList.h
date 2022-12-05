#pragma once

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
    popNthElementGotEmptyList,
    getNthValueGotNullPointer,
    getNthValueGotEmptyList
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