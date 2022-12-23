#include "upgradedParenthesesBalance.h"
#include <stdio.h>

// Тестовая проверка двух корректных случаев и трёх некорректных.
bool test(void) {
    BalanceErrorCode testErrorCode = noErrorsInBalance;

    char* testString1 = "";
    char* testString2 = "{(){()}[{}]}";
    char* testString3 = "{(})";
    char* testString4 = "{()}[";
    char* testString5 = ")(";

    bool testResult1 = upgradedParenthesesBalance(testString1, &testErrorCode);
    bool testResult2 = upgradedParenthesesBalance(testString2, &testErrorCode);
    bool testResult3 = upgradedParenthesesBalance(testString3, &testErrorCode);
    bool testResult4 = upgradedParenthesesBalance(testString4, &testErrorCode);
    bool testResult5 = upgradedParenthesesBalance(testString5, &testErrorCode);

    return testResult1 && testResult2 && !testResult3 && !testResult4 && !testResult5 && !testErrorCode;
}

int main(void) {
    if (!test()) {
        printf("Test failed\n");
        return -1;
    }
    else {
        printf("*Test passed*\n\n");
    }

    BalanceErrorCode errorCode = noErrorsInBalance;
    char* string = "[({()[]{}})]";

    bool result = upgradedParenthesesBalance(string, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    printf(result ? "Result: true\n" : "Result: false\n");

    return 0;
}
