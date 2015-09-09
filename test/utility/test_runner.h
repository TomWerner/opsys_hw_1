//
// Created by Test on 8/25/15.
//

#include <stdbool.h>

#ifndef TESTPROJ_TEST_RUNNER_H
#define TESTPROJ_TEST_RUNNER_H

bool assertEqualsI(int expected, int actual);
bool assertEqualsIm(char* message, int expected, int actual);

bool assertEqualsS(char* expected, char* actual);
bool assertEqualsSm(char* message, char* expected, char* actual);

bool assertEqualsL(long expected, long actual);
bool assertEqualsLm(char* message, long expected, long actual);

bool assertNull(void* value);
bool assertNullm(char* message, void* value);

bool assertNotNull(void* value);
bool assertNotNullm(char* message, void* value);

bool assertFalse(bool value);
bool assertFalsem(char* message, bool value);

bool assertTrue(bool value);
bool assertTruem(char* message, bool value);

void nameTest(char** testNameArg, char* testName);

int runTests(int numTests, bool (**tests) (char** testName));

#endif //TESTPROJ_TEST_RUNNER_H
