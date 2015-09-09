//
// Created by twrner on 8/31/15.
//

#include <stdio.h>

int main() {
    int nMinus1 = 1;
    int nMinus2 = 0;
    int newNumber;

    printf("%d\n", 1); // Print the first one
    for (int i = 0; i < 19; i++) {
        newNumber = (nMinus1 + nMinus2);
        printf("%d\n", newNumber);
        nMinus2 = nMinus1;
        nMinus1 = newNumber;
    }

    return 0;
}