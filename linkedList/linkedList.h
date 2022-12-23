#pragma once

// ���� ������:
typedef enum ListErrorCodes {
    noErrors,
} ListErrorCodes;

typedef int Value;

// ��� "������"
typedef struct List List;

// ������� ������.
// ���������� ��������� �� ��������� ������ ��� NULL, ���� ������� �� �������.
// ���� ������� �� ������� - ������ �� ���������, ������ ������� �� �����.
List* createList(ListErrorCodes* errorCode);

// �������� ������� � ������.
void addElement(Value value, List* list, ListErrorCodes* errorCode);

// ������� ������� �� ������.
void deleteElement(Value value, List* list, ListErrorCodes* errorCode);

// ����������� ���� ������.
void printList(ListErrorCodes* errorCode);

// ������� ������.
void deleteList(ListErrorCodes* errorCode);
