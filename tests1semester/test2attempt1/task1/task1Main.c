#include <stdio.h>
#include <stdbool.h>
#include "task1.h"
#include "tests.h"

int main(void) {
    if (!testForCreateAndDeleteList() || !testForPushIsSymmetricalAndClear() || !testForFill() || !testForIsSymmetrical()) {
        printf("Tests failed.\n");
        return -1;
    }
    else {
        printf("*tests passed*\n");
        printf("------------------\n\n");
    }

    int errorCode = 0;

    DoublyLinkedList* doublyLinkedList = createDoublyLinkedList(&errorCode);
    if (errorCode) {
        printf("Cannot create a list\n");
        return -1;
    }

    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Cannot open the file\n");
        return -1;
    }

    fill(file, doublyLinkedList, &errorCode);
    if (errorCode) {
        printf("Unable to fill\n");
        return -1;
    }

    fclose(file);

    bool result = isSymmetrical(doublyLinkedList, &errorCode);
    if (errorCode) {
        printf("Something wrong with isSymmetrical\n");
        return -1;
    }

    printf(result ? "This list is symmetrical\n" : "This list is not symmetrical\n");

    clear(doublyLinkedList, &errorCode);
    if (errorCode) {
        printf("Cannot clear the list\n");
        return -1;
    }

    deleteList(doublyLinkedList, &errorCode);
    if (errorCode) {
        printf("Cannot delete the list\n");
        return -1;
    }

    return 0;
}