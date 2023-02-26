#pragma once

#define NUMBER_OF_DIGITS 32

// ���� ������ ����� � ����������.
// ��������� �� ������������, ���������� �������� �����.
int integerInput(void);

// ������� �������� ����� �� �����������.
// �� ���� ��������� ���������� ����� � ��������� �� ������, ��� ����� ��������� �������� �����.
// ������� ���� ��������� ����� � ������� ����� ����������� ������, ������� �����.
void createBinary(int decimal, int* arrayForBinary);

// ����������� �������� ����� (������ � ���).
// �������� ������ ������ ������, � ������, �� ������ �������� ����� �������� ����� ������� (��. createBinary).
void printBinary(int* binary);

// ������� ��� �������� �����.
// ���������� �����������, ������ �������� � ����� ������������.
// �� ���� ��������� ��� ���������: �� ������� �� ���������� � �� ������ ��� ����������.
void addBinary(int* firstSummand, int* secondSummand, int* result);

// ������������� ���������� �����.
// ���� �� ������� ��������� ����� �������� ������ ������ (�� ������� ����� � �������).
// "�����������" �� � ��������� ���, �� ������ �������� ����� ����� �����.
int createDecimal(int* binary);