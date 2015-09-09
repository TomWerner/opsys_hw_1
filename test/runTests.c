//
// Created by Test on 8/25/15.
//

#include <stdio.h>
#include "utility/test_runner.h"
#include "linkedlist/doubly_linked_list_test.h"

#define NUMBER_OF_TESTS 16

void printBannerMessage(char* message) ;

int main() {
    bool (*tests[NUMBER_OF_TESTS]) (char** testNames) = {
            // --- Doubly linked list tests ---
            testDLCreateDLList,

            testDLAddAfterWithOneValue,
            testDLAddAfterWithNextValue,
            testDLAddAfterWithNullHead,

            testDLAddBeforeWithNextValue,
            testDLAddBeforeWithOneValue,
            testDLAddBeforeWithNullHead,

            testDLEmptyNullList,
            testDLEmptyOneNode,
            testDLEmptyMultipleNodes,

            testDLSortEmptyList,
            testDLSortSingleElem,
            testDLSortTwoElemInOrder,
            testDLSortTwoElemOutOfOrder,
            testDLSortMultiInOrder,
            testDLSortMultiOutOfOrder,
    };
    /**
     * 1: first 20 fibonacci
     * 2: takes in N, prints all numbers N is divisible by
     * 3: copies two files: command line args the source and dest, located in current directory, warning if dest already exists and prompts if they want to proceed
     * 4: doubly linked list with strings: init, add to end, empty list, print elems of list
     * 5: sort elems of list in lexical order using bubble sort
     * 5: union intersection on sets of ints, 0 to N, given when set created, stored as linked lists or arrays
     */

    int result = runTests(NUMBER_OF_TESTS, tests);

    if (result > 0) {
        printBannerMessage("Failure :(");
        return 1;
    }

    printBannerMessage("Success!");
    return 0;
}

void printBannerMessage(char* message) {
    printf("****************************************\n");
    printf("*\n");
    printf("*    %s\n", message);
    printf("*\n");
    printf("****************************************\n");
}