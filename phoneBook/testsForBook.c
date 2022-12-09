#include "testsForBook.h"

#include <stdio.h>

// Структура для записей телефонной книги.
struct PhonebookStruct {
    char name[51];
    char phone[51];
};

bool testForInitialReading(void) {
    PhonebookStruct book[3];
    int counterOfRecords = 0;

    FILE* fileForReading = fopen("fileForTestReading.txt", "r");

    initialFileReading(fileForReading, book, &counterOfRecords);

    fclose(fileForReading);

    if (counterOfRecords != 3) {
        return false;
    }

    if (book[0].name != "alexander" || book[0].phone != "123") {
        return false;
    }

    if (book[1].name != "abdullah" || book[1].phone != "456") {
        return false;
    }

    if (book[2].name != "mario" || book[2].phone != "789") {
        return false;
    }

    return true;
}