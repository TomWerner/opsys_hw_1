//
// Created by twrner on 8/31/15.
//

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 10000

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Problem3 incorrectly called. Usage:\n");
        printf("./Problem3 <src file name> <dest file name>\n");
        return 1;
    }
    char* srcPath = argv[1];
    char* destPath = argv[2];

    FILE* srcFile = fopen(srcPath, "r");
    if (srcFile == NULL) {
        printf("Could not open source file '%s'.\nExiting program.", srcPath);
        return 1;
    }

    bool writeToFile = true;
    if (access(destPath, F_OK) != -1) {
        // File exists
        printf("Destination file, '%s', already exists. Overwrite file? (y\\n): ", destPath);
        char buffer[4];
        fgets(buffer, 4, stdin);

        if (buffer[0] == 'Y' || buffer[0] == 'y') {
            writeToFile = true;
        }
        else {
            printf("Copy aborted by user.\n");
            writeToFile = false;
        }
    }

    if (writeToFile) {
        FILE* destFile = fopen(destPath, "w");
        if (destFile == NULL) {
            printf("Could not open destination file '%s'", destPath);
        }
        else {
            char fileBuffer[BUFFER_SIZE];
            while (true) {
                size_t bytesRead = fread(fileBuffer, sizeof(char), sizeof(char) * BUFFER_SIZE, srcFile);
                if (bytesRead == 0) {
                    break;
                }

                size_t bytesWritten = fwrite(fileBuffer, sizeof(char), sizeof(char) * bytesRead, destFile);
                if (bytesWritten == 0) {
                    printf("Error writing data to file.\n");
                    return 1;
                }
            }
            fclose(destFile);
        }
    }
    fclose(srcFile);

    return 0;
}