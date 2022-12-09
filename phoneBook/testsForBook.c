#include "testsForBook.h"

#include <stdio.h>
#include <string.h>

// Структура для записей телефонной книги.
struct PhonebookStruct {
    char name[51];
    char phone[51];
};

bool testForInitialReadingAndSearch(void) {
    // Создание нужных структур, чтение из файла.
    PhonebookStruct book[3];
    int counterOfRecords = 0;

    FILE* fileForReading = fopen("fileForTestReading.txt", "r");

    initialFileReading(fileForReading, book, &counterOfRecords);

    fclose(fileForReading);

    // Проверка, как считался файл.
    // Проверка количества записей и каждой отдельной записи.
    if (counterOfRecords != 3) {
        return false;
    }

    if (strcmp(book[0].name, "alexander\n") || strcmp(book[0].phone, "123\n")) {
        return false;
    }

    if (strcmp(book[1].name, "abdullah\n") || strcmp(book[1].phone, "456\n")) {
        return false;
    }

    if (strcmp(book[2].name, "mario\n") || strcmp(book[2].phone, "789\n")) {
        return false;
    }

    // Поиск с рассчётом на положительный результат (такие записи действительно существуют в тестовом файле).
    char stringForCompareName[51] = "abdullah\n";
    char stringForComparePhone[51] = "789\n";

    int arrayForMatches[100] = { 0 };
    int numberOfMatches = 0;

    bool searchResultForName = search(book, stringForCompareName, arrayForMatches, &numberOfMatches, counterOfRecords, 1);
    if (!searchResultForName || arrayForMatches[0] != 1 || numberOfMatches != 1) {
        return false;
    }

    bool searchResultForPhone = search(book, stringForComparePhone, arrayForMatches, &numberOfMatches, counterOfRecords, 2);
    if (!searchResultForPhone || arrayForMatches[0] != 2 || numberOfMatches != 1) {
        return false;
    }

    // Поиск с рассчётом на отрицательный результат (таких записей не существует в тестовом файле).
    char stringForCompareName2[51] = "karen\n";
    char stringForComparePhone2[51] = "951\n";

    bool searchResultForName2 = search(book, stringForCompareName2, arrayForMatches, &numberOfMatches, counterOfRecords, 1);
    if (searchResultForName2) {
        return false;
    }

    bool searchResultForPhone2 = search(book, stringForComparePhone2, arrayForMatches, &numberOfMatches, counterOfRecords, 2);
    if (searchResultForPhone2) {
        return false;
    }

    return true;
}

bool testForRecordToFile(void) {
    PhonebookStruct book[3] = { {"user1\n", "123\n"}, {"user2\n", "456\n"}, {"user3\n", "789\n"} };
    int counterOfRecords = 3;

    const char* fileName = "fileForTestRecord.txt";

    recordToFile(book, fileName, counterOfRecords);

    counterOfRecords = 0;

    PhonebookStruct bookForCheck[3] = { 0 };

    FILE* file = fopen(fileName, "r");
    initialFileReading(file, bookForCheck, &counterOfRecords);
    fclose(file);

    if (counterOfRecords != 3) {
        return false;
    }

    for (int i = 0; i < 3; ++i) {
        if (strcmp(book[i].name, bookForCheck[i].name) || strcmp(book[i].phone, bookForCheck[i].phone)) {
            return false;
        }
    }

    return true;
}