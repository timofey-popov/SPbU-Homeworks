#pragma once

#include <stdbool.h>
#include <stdio.h>

// ��������� ��� ������� � ���������� �����.
typedef struct PhonebookStruct PhonebookStruct;

// ��������� ������ ����� � ������ ��������.
void initialFileReading(FILE* file, PhonebookStruct* book, int* counterOfRecords);

// ����� ������ � ������� ��������.
bool search(PhonebookStruct* book, char* stringForCompare, int* arrayForMatches, int* numberOfMatches, int counterOfRecords, int mode);

// �������� ������ �������� � ����.
int recordToFile(PhonebookStruct* book, const char* fileName, int counterOfRecords);
