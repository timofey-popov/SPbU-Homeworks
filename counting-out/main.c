#include "circularList.h"

#include <stdio.h>

// Вспомогательная функция. Полностью очищает поток ввода.
// Нужно использовать аккуратно, так как если в потоке ничего нет, функция будет ждать следующего ввода и очистит один симол этого ввода (или весь ввод?).
void customFlush(void) {
    int junk1 = scanf_s("%*[^\n]");
    char junk2 = getchar();
}

int getPositiveInteger(void) {
    int valueToReturn = 0;
    
    int correctnessCheck = scanf_s("%d", &valueToReturn);

    while (!correctnessCheck || (valueToReturn < 1)) {
        customFlush();
        printf("Invalid input. Try again:\n");
        correctnessCheck = scanf_s("%d", &valueToReturn);
    }

    return valueToReturn;
}

bool isAnError(ListErrors* errorCode, CircularList* list) {
    if (*errorCode) {
        printf("An error occured: %d", *errorCode);
        deleteList(list, &errorCode);
        return 1;
    }

    return 0;
}

int main(void) {
    printf("Enter n:\n");
    int n = getPositiveInteger();
    printf("Enter m:\n");
    int m = getPositiveInteger();
    
    ListErrors listError = noErrors;
    CircularList* list = createList(&listError);
    if (listError || list == NULL) {
        return listError;
    }

    // Набиваем в список n номеров воинов по порядку:
    for (int i = 1; i <= n; ++i) {
        addToList(i, list, &listError);
        if (isAnError(&listError, list)) {
            return listError;
        }
    }

    int result = calculateSuitablePosition(n, m, list, &listError);
    if (isAnError(&listError, list)) {
        return listError;
    }

    deleteList(list, &listError);
    if (listError) {
        return listError;
    }
    printf("Result: take position %d\n\n", result);

    return 0;
}