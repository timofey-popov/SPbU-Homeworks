#include "phoneBook.h"

#include "testsForBook.h"
#include <string.h>
#include <stdbool.h>

// Структура для записей телефонной книги.
struct PhonebookStruct {
    char name[51];
    char phone[51];
};

// Вспомогательная функция. Полностью очищает поток ввода.
// Нужно использовать аккуратно, так как если в потоке ничего нет, функция будет ждать следующего ввода и очистит один симол этого ввода (или весь ввод?).
void customFlush(void) {
    int junk1 = scanf_s("%*[^\n]");
    char junk2 = getchar();
}

// Функция для обработки пользовательского ввода (строк).
// На вход принимает массив для записи и размер этого массива.
void stringsInput(char* arrayForInput, int arraySize) {
    char* isStringInputCorrect = fgets(arrayForInput, arraySize, stdin);

    while (!isStringInputCorrect) {
        customFlush();
        printf("Wrong input. Try again:\n");
        isStringInputCorrect = fgets(arrayForInput, arraySize, stdin);
    }
}

// Функция для начального считывания данных из файла.
// Считывает количество записей и сами записи в соответствующие переменные.
// Если файла не существует, он будет создан.
// На вход принимает указатель на массив структур и на счётчик записей.
void initialFileReading(FILE* file, PhonebookStruct* book, int* counterOfRecords) {
    int fileEmptinessChecker = fscanf_s(file, "%d", counterOfRecords);

    if (fileEmptinessChecker > 0) {
        fgetc(file);
        for (int i = 0; i < *counterOfRecords; ++i) {
            fgets(book[i].name, 51, file);
            fgets(book[i].phone, 51, file);
        }
    }
}

// Функция получения номера действия от пользователя.
// Записывает введённый номер действия в специальную переменную.
// На вход принимает указатель на переменную с текущим номером действия.
void numberOfActionInput(short* statusForChange) {

    printf("Choose an action:\n0 - exit\n1 - make a record\n"
        "2 - show all records\n3 - find a number by name\n4 - find a name by number\n5 - save data to file\n\n");

    int inputCorrectnessCheck = scanf_s("%hi", statusForChange);
    while (!inputCorrectnessCheck || *statusForChange < 0 || *statusForChange > 5) {
        customFlush();
        printf("Wrong input. Try again:\n");
        inputCorrectnessCheck = scanf_s("%hi", statusForChange);
    }
}

// Функция, которая создаёт запись в массиве структур и прибавляет счётчик после каждой созданной записи.
// На вход принимает указатель на счётчик и на массив структур.
void newRecordCreate(int* counterOfRecords, PhonebookStruct* arrayForRecord) {

    //Очищаем поток, так как в нём уже находится символ перевода строки после введённого пользователем номера действия.
    customFlush();

    printf("\nEnter the name (no more than 50 characters):\n");
    stringsInput(arrayForRecord[*counterOfRecords].name, 51);

    printf("Enter the phone (no spaces, no more than 50 characters):\n");
    stringsInput(arrayForRecord[*counterOfRecords].phone, 51);

    ++*counterOfRecords;
    printf("\nRecord created successfully.\n\n");
}

// Функция распечатки всех имеющихся записей.
// На вход принимает указатель на массив структур и количество имеющихся записей.
void printWholeBook(PhonebookStruct* book, int counterOfRecords) {
    if (!counterOfRecords) {
        printf("\nThere's no records in the phonebook.\n\n");
        return;
    }

    printf("\nHere are all the records:\n\n");
    for (int i = 0; i < counterOfRecords; ++i) {
        printf("%s%s\n", book[i].name, book[i].phone);
    }
}

void printForSearch(PhonebookStruct* book, int* matches, int numberOfMatches) {
    for (int i = 0; i < numberOfMatches; ++i) {
        printf("%s%s\n", book[matches[i]].name, book[matches[i]].phone);
    }
}

// Функция поиска записей.
// На вход принимает указатель на массив структур, количество существующих записей и режим поиска (1 или 2).
// Режим 1 - поиск по имени. Режим 2 - поиск по телефону.
bool search(PhonebookStruct* book, char* stringForCompare, int* arrayForMatches, int* numberOfMatches, int counterOfRecords, int mode) {
    *numberOfMatches = 0;

    bool isFound = false;

    switch (mode) {
    case 1:
        for (int i = 0; i < counterOfRecords; ++i) {
            if (!strcmp(book[i].name, stringForCompare)) {
                arrayForMatches[*numberOfMatches] = i;
                *numberOfMatches += 1;
                isFound = true;
            }
        }
        break;
    case 2:
        for (int i = 0; i < counterOfRecords; ++i) {
            if (!strcmp(book[i].phone, stringForCompare)) {
                arrayForMatches[*numberOfMatches] = i;
                *numberOfMatches += 1;
                isFound = true;
            }
        }
        break;
    }

    return isFound;
}

// Функция записи данных в файл.
// На вход принимает указатель на массив структур и количество существующих записей.
int recordToFile(PhonebookStruct* book, const char* fileName, int counterOfRecords) {
    FILE* file = fopen(fileName, "w");

    if (file == NULL) {
        return -1;
    }

    fprintf(file, "%d\n", counterOfRecords);

    for (int i = 0; i < counterOfRecords; ++i) {
        fputs(book[i].name, file);
        fputs(book[i].phone, file);
    }

    fclose(file);
    return 0;
}

int main(void) {
    if (!testForInitialReadingAndSearch() || !testForRecordToFile()) {
        printf("Tests failed\n");
        return -1;
    }
    else {
        printf("*tests passed*\n\n");
    }

    PhonebookStruct phonebookArray[100];

    // Переменная для хранения номера действия.
    short currentStatus = 1;

    // Переменная для хранения количества записей.
    // Считывается из файла при запуске программы, увеличивается с каждой следующей записью.
    int counterOfRecords = 0;

    const char* fileName = "phoneBook.txt";

    FILE* fileWithRecords = fopen("phoneBook.txt", "a+");
    initialFileReading(fileWithRecords, phonebookArray, &counterOfRecords);
    fclose(fileWithRecords);

    char stringForCompare[51];
    int matches[100] = { 0 };
    int numberOfMatches = 0;

    bool isFound = false;

    // Повторяющийся запрос ввода от пользователя.
    while (currentStatus) {
        numberOfActionInput(&currentStatus);

        switch (currentStatus) {
        case 0:
            break;
        case 1:
            newRecordCreate(&counterOfRecords, phonebookArray);
            break;
        case 2:
            printWholeBook(phonebookArray, counterOfRecords);
            break;
        case 3:
            customFlush();
            printf("\nEnter the name:\n");
            stringsInput(stringForCompare, 51);

            isFound = search(phonebookArray, stringForCompare, matches, &numberOfMatches, counterOfRecords, 1);

            printf("\nSearch results:\n\n");
            isFound ? printForSearch(phonebookArray, matches, numberOfMatches) : printf("No such records in the book\n\n");

            break;
        case 4:
            customFlush();
            printf("\nEnter the phone without spaces:\n");
            stringsInput(stringForCompare, 51);

            isFound = search(phonebookArray, stringForCompare, matches, &numberOfMatches, counterOfRecords, 2);

            printf("\nSearch results:\n\n");
            isFound ? printForSearch(phonebookArray, matches, numberOfMatches) : printf("No such records in the book\n\n");

            break;
        case 5:
            recordToFile(phonebookArray, fileName, counterOfRecords) ? printf("No such file\n") : printf("\nData saved successfully.\n\n");
            break;
        }
    }

    return 0;
}