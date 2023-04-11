#pragma once

#include <stdbool.h>

// ���� ������.
typedef enum ErrorCodes {
    noErrors,
    memoryAllocationError,
    gotNullPointer,
    treeIsEmpty
} ErrorCodes;

// ��� "�������".
// ��������� ������������ �������� ������ � ����� �������� �� �����.
typedef struct Dictionary Dictionary;

// ��� ������ ��� �������� � ������� ��������.
typedef int Value;

// ������� �������. ���������� ��������� �� ��������� ������� ��� NULL, ���� ��������� ������.
Dictionary* createDictionary(ErrorCodes* errorCode);

// �������� �������� � ������� � �������� ������.
// �� ���� ��������� ��������, ����, ������� � ���������� � ����� ������.
// ���� ����� ���� ��� ��� � �������, �������� ���������� �� �����.
void addValue(Value value, int key, Dictionary* dictionary, ErrorCodes* errorCode);

// �������� �������� �� �����. �� ���� ��������� ����, ������� � ���������� � ����� ������.
// ���� ������ ����� � ������� ���, ���������� NULL � �� �������� ��� ������.
Value getValueByKey(int key, Dictionary* dictionary, ErrorCodes* errorCode);

// ����� true, ���� ����� ���� ���� � �������, � false � �������� ������.
bool isSuchKey(int key, Dictionary* dictionary, ErrorCodes* errorCode);

// ������� ���� � ��������� � ��� �������� �� �������.
// ���� ������ ����� � ������� ���, ������ �� ��������� � ��� ������ �� ����������.
void deleteKeyAndItsValue(int key, Dictionary* dictionary, ErrorCodes* errorCode);

// ������� �������. ���������� true, ���� �� ������ �������, � false � ��������� ������.
void deleteDictionary(Dictionary* dictionaryToRemove, ErrorCodes* errorCode);
