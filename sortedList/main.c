#include "sortedList.h"

#include <stdio.h>
#include <stdbool.h>

// Вспомогательная функция. Полностью очищает поток ввода.
// Нужно использовать аккуратно, так как если в потоке ничего нет, функция будет ждать следующего ввода и очистит один симол этого ввода (или весь ввод?).
void customFlush(void) {
    int junk1 = scanf_s("%*[^\n]");
    char junk2 = getchar();
}

// Функция получения номера действия от пользователя.
// Записывает введённый номер действия в специальную переменную.
// На вход принимает указатель на переменную с текущим номером действия.
void numberOfActionInput(short* statusForChange) {
    printf("Choose an action:\n0 - exit\n1 - add a value\n"
        "2 - delete a value\n3 - print the whole list\n\n");

    int inputCorrectnessCheck = scanf_s("%hi", statusForChange);
    while (!inputCorrectnessCheck || *statusForChange < 0 || *statusForChange > 3) {
        customFlush();
        printf("Wrong input. Try again:\n");
        inputCorrectnessCheck = scanf_s("%hi", statusForChange);
    }
}

void inputForIntegers(int* variableForValue) {
    int correctnessCheck = scanf_s("%d", variableForValue);

    while (!correctnessCheck) {
        customFlush();
        printf("Invalid input. Try again:\n");
        int correctnessCheck = scanf_s("%d", variableForValue);
    }
}

bool isAnError(ListErrors* errorCode, SortedList* list) {
    if (*errorCode) {
        printf("An error occured: %d", *errorCode);
        deleteList(list, &errorCode);
        return 1;
    }

    return 0;
}

int main(void) {
    // Переменная для хранения номера действия.
    short currentStatus = 1;
    // Переменная для сохранения пользовательского ввода.
    int userValue = 0;
    ListErrors listError = noErrors;

    SortedList* myList = createList(&listError);
    if (listError) {
        return listError;
    }

    // Повторяющийся запрос ввода от пользователя.
    while (currentStatus) {
        numberOfActionInput(&currentStatus);

        switch (currentStatus) {
        case 0:
            break;
        case 1:
            printf("Enter a value to add:\n");
            inputForIntegers(&userValue);

            addToList(userValue, myList, &listError);
            if (isAnError(&listError, myList)) {
                return listError;
            }

            printf("%d added successfully\n\n", userValue);
            break;
        case 2:
            printf("Enter a value to delete:\n");
            inputForIntegers(&userValue);

            deleteFromList(userValue, myList, &listError);
            if (isAnError(&listError, myList)) {
                return listError;
            }

            printf("%d deleted successfully\n\n", userValue);
            break;
        case 3:
            printWholeList(myList, &listError);
            if (isAnError(&listError, myList)) {
                return listError;
            }

            break;
        }
    }

    return 0;
}
