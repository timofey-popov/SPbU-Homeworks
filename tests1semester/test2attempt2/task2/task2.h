#pragma once

#include <stdbool.h>

// ���� ������.
typedef enum ErrorCodesForSet {
    noErrors,
    memoryAllocationError,
    gotNullPointer
} ErrorCodesForSet;

// ��� ������ ��� ��������� ��������.
typedef int Value;

// ��� ���������.
typedef struct Set Set;

// ������� ����� ��������� �� ������ ��������.
// �������� ������, ����� ���� ������������ � �� �������� ������� (freeSet);
Set* createSet(Value value, ErrorCodesForSet* errorCode);

// ���������� ��� ��������� � ����.
// �� �������� ������� ������. � ������ ������ ������� ����� ������ �������� ���������.
Set* unite(Set* set1, Set* set2, ErrorCodesForSet* errorCode);

// �������� �� ��������� ���������� ������ ���������.
bool isTheSameSet(Set* set1, Set* set2, ErrorCodesForSet* errorCode);

// ������� �� ���������, � ������� "�����" ��� ������������.
void freeSet(Set* set, ErrorCodesForSet* errorCode);