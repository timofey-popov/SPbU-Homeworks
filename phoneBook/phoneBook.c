#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[51];
    char phone[51];
} PhonebookStruct;

void customFlush(void) {
    scanf("%*[^\n]");
    getchar();

    return;
}

void stringsInput(char* arrayForInput, int arraySize) {
    char* isStringInputCorrect = fgets(arrayForInput, arraySize, stdin);
    while (!isStringInputCorrect) {
        customFlush();
        printf("Wrong input. Try again:\n");
        isStringInputCorrect = fgets(arrayForInput, arraySize, stdin);
    }

    return;
}

// Функция, которая создаёт запись в массиве структур и прибавляет счётчик после каждой созданной записи.
// На вход принимает указатель на счётчик и на массив структур.
void newRecordCreate(int* counterOfRecords, PhonebookStruct* arrayForRecord) {
    customFlush();

    char nameWithinFunction[51];
    char phoneWithinFunction[51];

    printf("\nEnter the name (no more than 50 characters):\n");
    stringsInput(nameWithinFunction, 51);

    printf("Enter the phone (no more than 50 characters incl. spaces):\n");
    stringsInput(phoneWithinFunction, 51);

    strcpy(arrayForRecord[*counterOfRecords].name, nameWithinFunction);
    strcpy(arrayForRecord[*counterOfRecords].phone, phoneWithinFunction);

    ++* counterOfRecords;
    printf("\nRecord created successfully.\n\n");
    return;
}

void printWholeBook(PhonebookStruct* book, int counterOfRecords) {
    if (!counterOfRecords) {
        printf("\nThere's no records in the phonebook.\n\n");
        return;
    }

    printf("\nHere are all the records:\n\n");
    for (int i = 0; i < counterOfRecords; ++i) {
        printf("%s%s\n", book[i].name, book[i].phone);
    }

    return;
}

// Мод 1 - поиск по имени. Мод 2 - поиск по телефону.
void search(PhonebookStruct* book, char* stringForCompare, int counterOfRecords, int mode) {
    bool isFound = false;

    printf("\nSearch results:\n\n");

    switch (mode) {
    case 1:
        for (int i = 0; i < counterOfRecords; ++i) {
            if (!strcmp(book[i].name, stringForCompare)) {
                printf("%s%s\n", book[i].name, book[i].phone);
                isFound = true;
            }
        }
        break;
    case 2:
        for (int i = 0; i < counterOfRecords; ++i) {
            if (!strcmp(book[i].phone, stringForCompare)) {
                printf("%s%s\n", book[i].name, book[i].phone);
                isFound = true;
            }
        }
    }

    if (!isFound) {
        printf("No such records in the book\n\n");
    }

    return;
}

void phoneByName(PhonebookStruct* book, int counterOfRecords) {
    customFlush();

    char name[51];

    printf("\nEnter the name:\n");
    stringsInput(name, 51);

    search(book, name, counterOfRecords, 1);

    return;
}

void nameByPhone(PhonebookStruct* book, int counterOfRecords) {
    customFlush();

    char phone[51];

    printf("\nEnter the phone without spaces:\n");
    stringsInput(phone, 51);

    search(book, phone, counterOfRecords, 2);

    return;
}

void recordToFile(PhonebookStruct* book, int counterOfRecords) {
    FILE* file = fopen("phonebook.txt", "w");

    fprintf(file, "%d\n", counterOfRecords);

    for (int i = 0; i < counterOfRecords; ++i) {
        fputs(book[i].name, file);
        fputs(book[i].phone, file);
    }

    printf("\nData saved successfully.\n\n");
}

void initialFileReading(PhonebookStruct* book, int* counterOfRecords) {
    FILE* file = fopen("phonebook.txt", "a");
    int fileEmptynessChecker = fscanf(file, "%d", counterOfRecords);

    if (fileEmptynessChecker > 0) {
        fgetc(file);
        for (int i = 0; i < *counterOfRecords; ++i) {
            fgets(book[i].name, 51, file);
            fgets(book[i].phone, 51, file);
        }
    }

    fclose(file);
}

// Функция получения номера действия от пользователя.
void numberOfActionInput(short* statusForChange) {

    printf("Choose an action:\n0 - exit\n1 - make a record\n"
        "2 - show all records\n3 - find a number by name\n4 - find a name by number\n5 - save data to file\n\n");

    int isInputCorrect = scanf("%hi", statusForChange);
    while (!isInputCorrect || *statusForChange < 0 || *statusForChange > 5) {
        scanf("%*[^\n]");
        printf("Wrong input. Try again:\n");
        isInputCorrect = scanf("%hi", statusForChange);
    }
}

int main(void) {
    PhonebookStruct phonebookArray[100];

    // Переменная для хранения номера действия.
    short currentStatus = 1;

    // Переменная для хранения количества записей.
    // Считывается из файла при запуске программы, увеличивается с каждой следующей записью. 
    int counterOfRecords = 0;

    initialFileReading(phonebookArray, &counterOfRecords);

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
            phoneByName(phonebookArray, counterOfRecords);
            break;
        case 4:
            nameByPhone(phonebookArray, counterOfRecords);
            break;
        case 5:
            recordToFile(phonebookArray, counterOfRecords);
            break;
        }
    }

    for (int i = 0; i < counterOfRecords; ++i) {
        printf("\nName: %sPhone: %s\n", phonebookArray[i].name, phonebookArray[i].phone);
    }
}

// Вопросы: