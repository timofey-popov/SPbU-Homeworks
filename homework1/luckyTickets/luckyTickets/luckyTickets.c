#include <stdio.h>

// Подсчёт количества "счастливых" билетов (формата 111 003: 1+1+1 = 0+0+3).
int main(void) {
    char countingArray[29] = { 0 };

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k)
                countingArray[i + j + k]++;
        }
    }

    int answer = 0;

    for (int i = 1; i < 28; ++i)
        answer += countingArray[i] * countingArray[i];

    printf("There are %d lucky tickets\n", answer);

    return 0;
}