//
// Created by Test on 8/25/15.
//

#ifndef TESTPROJ_DOUBLY_LINKED_LIST_TEST_H
#define TESTPROJ_DOUBLY_LINKED_LIST_TEST_H

#include <stdbool.h>

bool testDLCreateDLList(char** testName);

bool testDLAddAfterWithNextValue(char** testName);
bool testDLAddAfterWithNullHead(char** testName);
bool testDLAddAfterWithOneValue(char** testName);

bool testDLAddBeforeWithNextValue(char** testName);
bool testDLAddBeforeWithOneValue(char** testName);
bool testDLAddBeforeWithNullHead(char** testName);

bool testDLEmptyNullList(char** testName);
bool testDLEmptyOneNode(char** testName);
bool testDLEmptyMultipleNodes(char** testName);

bool testDLSortEmptyList(char** testName);
bool testDLSortSingleElem(char** testName);
bool testDLSortTwoElemOutOfOrder(char** testName);
bool testDLSortTwoElemInOrder(char** testName);
bool testDLSortMultiInOrder(char** testName);
bool testDLSortMultiOutOfOrder(char** testName);

#endif //TESTPROJ_DOUBLY_LINKED_LIST_TEST_H
