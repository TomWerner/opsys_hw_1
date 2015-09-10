//
// Created by twrner on 8/31/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Problem2 incorrectly called. Usage:\n");
        printf("./Problem2 <your number here>\n");
        return 1;
    }

    long parameter = labs(strtol(argv[1], NULL, 10));

    for (int i = 1; i < (int) sqrtl(parameter) + 1; i++) {
        if (parameter % i == 0) {
            printf("(+/-) %d\n", i);
            if (i != (parameter / i)) {
                printf("(+/-) %d\n", (int) (parameter / i));
            }
        }
    }

    return 0;
}
