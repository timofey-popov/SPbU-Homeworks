#pragma once

#include <stdbool.h>

// ���������, ���������� ������� ��������� �������.
// ������ ����� ����� � ������ �� ��������� ������� � �������
typedef struct Unit
{
    int value;
    struct Unit* next;
} Unit;

// ������� ��� ���������� �������� � ����� �������.
void enqueue(int value, Unit** head, Unit** tail, int* errorCode);

// ������� ��� �������� �������� �� ������ �������.
int dequeue(Unit** head, Unit** tail, int* errorCode);

// ������� ��� ������� �������. ������� ��� ��������.
void clear(Unit** head, Unit** tail, int* errorCode);

// �������-�������� ������� �� �������.
// ���������� true, ���� ������� �����, � false � �������� ������.
bool isEmpty(Unit** head);