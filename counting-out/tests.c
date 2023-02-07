#include "tests.h"
#include "counting-out.h"

bool testForCalculating(void) {
    CountingOutErrors testErrorCode = noErrors;

    // ����� ��������� �������.
    int test1 = calculateSuitablePosition(5, 2, &testErrorCode);

    // ������ ������ ���������� 1.
    int test2 = calculateSuitablePosition(1, 100, &testErrorCode);
    
    // ��� ���� ������ ������ ������������ 1, ���� m ������, � 2 � ��������� ������.
    int test3 = calculateSuitablePosition(2, 120, &testErrorCode);
    int test4 = calculateSuitablePosition(2, 159, &testErrorCode);

    return (test1 == 3) && (test2 == 1) && (test3 == 1) && (test4 == 2);
}