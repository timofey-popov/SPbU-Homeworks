#pragma once

// ��� ������ � ������ ������ ������ ���������� errorCode � 0 �� 1.

// ��������� ��� ������� �����.
// �������� ��� ����: �������� � ��������� �� ���������� ������� �����.
typedef struct Unit {
    int value;
    struct Unit* previous;
} Unit;

