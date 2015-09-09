//
// Created by Test on 8/25/15.
//

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "test_runner.h"

int runTests(int numTests, bool (**tests) (char** testName)) {
    int failedTests = 0;
    char* testName[1] = { "Running tests..." };
    printf("%s\n\n", testName[0]);
    printf("----------------------------------------\n");

    for (int i = 0; i < numTests; i++) {
        if (tests[i](testName) == false) {
            failedTests++;
            printf("* TEST RESULT: Failure\n");
        }
        else {
            printf("* TEST RESULT: Success\n");
        }
        printf("----------------------------------------\n");
    }
    printf("\n\n");

    printf("%d tests failed out of %d total.\n\n", failedTests, numTests);

    return failedTests;
}

void nameTest(char **testNameArg, char *testName) {
    testNameArg[0] = testName;
    printf("* TEST NAME: %s\n", testName);
}

bool displayAssertFail(bool success, char* message, char* assertFail, ...) {
    if (success) {
        return true;
    }

    if (strlen(message) > 0) {
        printf("%s\n", message);
    }
    va_list args;
    va_start(args, assertFail);

    vprintf(assertFail, args);

    va_end(args);

    return false;
}

bool assertEqualsI(int expected, int actual) {
    return assertEqualsIm("", expected, actual);
}

bool assertEqualsIm(char* message, int expected, int actual) {
    return displayAssertFail((actual == expected), message, "Expected: %d, Actual: %d\n", expected, actual);
}

bool assertNull(void *value) {
    return assertNullm("", value);
}

bool assertNullm(char* message, void *value) {
    return displayAssertFail((value == NULL), message, "Value was not null\n");
}

bool assertNotNull(void *value) {
    return assertNotNullm("", value);
}

bool assertNotNullm(char* message, void *value) {
    return displayAssertFail((value != NULL), message, "Value was null\n");
}

bool assertFalse(bool value) {
    return assertFalsem("", value);
}

bool assertFalsem(char* message, bool value) {
    return displayAssertFail((value == false), message, "Value was true\n");
}

bool assertTrue(bool value) {
    return assertTruem("", value);
}

bool assertTruem(char* message, bool value) {
    return displayAssertFail((value == true), message, "Value was false\n");
}

bool assertEqualsL(long expected, long actual) {
    return assertEqualsLm("", expected, actual);
}

bool assertEqualsLm(char *message, long expected, long actual) {
    return displayAssertFail((actual == expected), message, "Expected: %lu, Actual: %lu\n", expected, actual);
}

bool assertEqualsS(char *expected, char *actual) {
    return assertEqualsSm("", expected, actual);
}

bool assertEqualsSm(char *message, char *expected, char *actual) {
    return displayAssertFail((strcmp(expected, actual) == 0), message, "Expected: %s, Actual: %s\n", expected, actual);
}
