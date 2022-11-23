#pragma once

// ��������� ��� ����������� ������.
typedef struct Unit {
    int value;
    struct Unit* next;
    struct Unit* prev;
} Unit;

// �������, ����������� ������� � ����� ������.
// ���������� 0, ���� �� ������ ������� � 1 � ��������� ������.
int push(int value, Unit** head, Unit** tail);

// �������, ��������� ��������� ������.
int clear(Unit** tail);

// �������, ����������� ������ ���������� �� �����.
int fill(FILE* file, Unit** head, Unit** tail);

// ������� �������� �� ��������������.
bool isSymmetrical(Unit** head, Unit** tail, int* errorCode);
