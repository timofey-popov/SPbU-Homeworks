#include <stdio.h>
#include <stdbool.h>

// Функция проверки строки на палиндром.
// На вход принимает размер строки БЕЗ символа завершения строки.
// Результат проверки печатает на экран, а в место вызова возвращает false или true.
bool isPalindrome(const char* string, int stringSize) {

    for (int i = 0; i < stringSize; ++i) {
        if (string[i] != string[stringSize - 1 - i]) {
            printf("\"%s\" is not a palindrome\n", string);
            return false;
        }
    }

    printf("\"%s\" is a palindrome\n", string);
    return true;
}

// Функция с тестами.
bool test(void) {
    printf("*Tests in progress*\n");
    const char testString1[6] = "ololo\0";
    const char testString2[6] = "OlolO\0";
    const char testString3[6] = "ololO\0";
    const char testString4[7] = "abobus\0";
    
    bool test1 = isPalindrome(testString1, 5);
    bool test2 = isPalindrome(testString2, 5);
    bool test3 = isPalindrome(testString3, 5);
    bool test4 = isPalindrome(testString4, 6);

    printf("*End of tests*\n\n");
    return (test1 && test2 && !test3 && !test4);
}

int main(void) {
    if (!test()) {
        printf("Test failed\n");
        return -1;
    }
    printf("*Test passed*\n\n\n");

    const char string1[16] = "step on no pets\0";
    const char string2[16] = "Step on no pets\0";

    isPalindrome(string1, 15);
    isPalindrome(string2, 15);

    return 0;
}