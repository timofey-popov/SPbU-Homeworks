#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 500

void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString) {
    for (int i = 1; i < printingArraySize + 1; ++i) {
        printf("%10d", arrayToPrint[i - 1]);
        if (i % numberOfElementsInOneString == 0)
            printf("\n");
    }

    printf("\n\n");
}

void charsCounter(FILE* file, int* alphabet) {
    char buffer = fgetc(file);

    while (buffer != EOF) {
        ++alphabet[(int)buffer];
        buffer = fgetc(file);
    }
}

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

bool test(void) {
    FILE* testFile = fopen("test.txt", "r");
    int* testAlphabet = calloc(500, sizeof(int));
    if (testAlphabet == NULL) {
        printf("Memory allocation error\n");
        return false;
    }

    charsCounter(testFile, testAlphabet);
    if (testAlphabet[32] == 2 && testAlphabet[10] == 2 && testAlphabet[97] == 1) {
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