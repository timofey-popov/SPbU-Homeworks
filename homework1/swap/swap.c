#include <stdio.h>

void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

    return;
}

int main(void)
{
    int firstVariable = 1;
    int secondVariable = 2;

    int* pointer1 = &firstVariable;
    int* pointer2 = &secondVariable;

    swap(pointer1, pointer2);

    printf("Now the first variable = %d and the second variable = %d\n", firstVariable, secondVariable);

    return 0;
}
