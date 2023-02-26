#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 500

// Считает количество символов, просто переводя их код в цифру и прибавляя 1 к соответствующей ячейке массива alphabet
void charsCounter(FILE* file, int* alphabet) {
    char buffer = fgetc(file);

    while (buffer != EOF) {
        ++alphabet[(int)buffer];
        buffer = fgetc(file);
    }
}

// Распечатывает получившиеся символы. 
// Если символ встретился хотя бы один раз, функция распечатает его и количество его вхождений в файл.
void printCharsFound(int* alphabet) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (alphabet[i] != 0) {
            if ((char)i == '\n')
                printf("Char \"Enter\" occurs % d times.\n", alphabet[i]);
            else if ((char)i == ' ')
                printf("Char \"Space\" occurs % d times.\n", alphabet[i]);
            else
                printf("Char \"%c\" occurs % d times.\n", (char)i, alphabet[i]);
        }
    }
}

// Проверяем корректность обработки заранее заданного файла.
bool test(void) {
    FILE* testFile = fopen("test.txt", "r");
    int* testAlphabet = calloc(500, sizeof(int));
    if (testAlphabet == NULL) {
        printf("Memory allocation error\n");
        return false;
    }

    charsCounter(testFile, testAlphabet);
    if (testAlphabet[32] == 2 && testAlphabet[10] == 2 && testAlphabet[97] == 1) {
        fclose(testFile);
        free(testAlphabet);

        return true;
    }

    fclose(testFile);
    free(testAlphabet);

    return false;
}

int main(void) {
    if (!test()) {
        printf("Tests failed\n");
        return -1;
    }

    int* alphabet = calloc(500, sizeof(int));
    if (alphabet == NULL) {
        printf("Memory allocation error\n");
        return -1;
    }

    FILE* file = fopen("task3.txt", "r");
    
    charsCounter(file, alphabet);
    printCharsFound(alphabet);

    fclose(file);
    free(alphabet);

    return 0;
}