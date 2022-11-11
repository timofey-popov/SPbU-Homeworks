#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Структура для записей телефонной книги.
typedef struct {
    char name[51];
    char phone[51];
} PhonebookStruct;

// Вспомогательная функция. Полностью очищает поток ввода.
// Нужно использовать аккуратно, так как если в потоке ничего нет, функция будет ждать следующего ввода и очистит этот ввод.
void customFlush(void) {
    scanf("%*[^\n]");
    getchar();
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
void initialFileReading(PhonebookStruct* book, int* counterOfRecords) {
    FILE* file = fopen("phonebook.txt", "a+");
    int fileEmptinessChecker = fscanf(file, "%d", counterOfRecords);

    if (fileEmptinessChecker > 0) {
        fgetc(file);
        for (int i = 0; i < *counterOfRecords; ++i) {
            fgets(book[i].name, 51, file);
            fgets(book[i].phone, 51, file);
        }
    }

    fclose(file);
}

// Функция получения номера действия от пользователя.
// Записывает введённый номер действия в специальную переменную.
// На вход принимает указатель на переменную с текущим номером действия.
void numberOfActionInput(short* statusForChange) {

    printf("Choose an action:\n0 - exit\n1 - make a record\n"
        "2 - show all records\n3 - find a number by name\n4 - find a name by number\n5 - save data to file\n\n");

    int isInputCorrect = scanf("%hi", statusForChange);
    while (!isInputCorrect || *statusForChange < 0 || *statusForChange > 5) {
        customFlush();
        printf("Wrong input. Try again:\n");
        isInputCorrect = scanf("%hi", statusForChange);
    }
}

// Функция, которая создаёт запись в массиве структур и прибавляет счётчик после каждой созданной записи.
// На вход принимает указатель на счётчик и на массив структур.
void newRecordCreate(int* counterOfRecords, PhonebookStruct* arrayForRecord) {

    //Очищаем поток, так как в нём уже находится символ перевода строки после введённого пользователем номера действия.
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

// Функция поиска записей.
// На вход принимает указатель на массив структур, ввод пользователя с искомой строкой, количество существующих записей режим поиска (1 или 2).
// Режим 1 - поиск по имени. Режим 2 - поиск по телефону.
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
        break;
    }

    if (!isFound) {
        printf("No such records in the book\n\n");
    }
}

// Функция обработки поискового запроса (найти телефон по номеру).
// На вход принимает указатель на массив структур и количество существующих записей.
// Далее обращается к функции поиска.
void findPhoneByName(PhonebookStruct* book, int counterOfRecords) {
    customFlush();

    char name[51];

    printf("\nEnter the name:\n");
    stringsInput(name, 51);

    search(book, name, counterOfRecords, 1);
}

// Функция обработки поискового запроса (найти номер по телефону).
// На вход принимает указатель на массив структур и количество существующих записей.
// Далее обращается к функции поиска.
void findNameByPhone(PhonebookStruct* book, int counterOfRecords) {
    customFlush();

    char phone[51];

    printf("\nEnter the phone without spaces:\n");
    stringsInput(phone, 51);

    search(book, phone, counterOfRecords, 2);
}

// Функция записи данных в файл.
// На вход принимает указатель на массив структур и количество существующих записей.
void recordToFile(PhonebookStruct* book, int counterOfRecords) {
    FILE* file = fopen("phonebook.txt", "w");

    fprintf(file, "%d\n", counterOfRecords);

    for (int i = 0; i < counterOfRecords; ++i) {
        fputs(book[i].name, file);
        fputs(book[i].phone, file);
    }

    printf("\nData saved successfully.\n\n");
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
            findPhoneByName(phonebookArray, counterOfRecords);
            break;
        case 4:
            findNameByPhone(phonebookArray, counterOfRecords);
            break;
        case 5:
            recordToFile(phonebookArray, counterOfRecords);
            break;
        }
    }

    return 0;
}