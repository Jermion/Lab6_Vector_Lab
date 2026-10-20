/**
* Author: Joshua Simon
 * Date: 10/12/2026
 * Description: Main file for the vector calculator
 **/

#include <stdio.h>
#include <string.h>
#include "ui.h"

int main(int argc, char *argv[]) {
    struct storage storage;

    // List the commands avaliable
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("Vector Calculator Help\n");
        printf("var = x y z        Create or replace a vector\n");
        printf("var                Display a vector\n");
        printf("var1 + var2        Add two vectors\n");
        printf("var1 - var2        Subtract two vectors\n");
        printf("var * number       Multiply a vector by a scalar\n");
        printf("number * var       Multiply a scalar by a vector\n");
        printf("result = operation Perform and store an operation\n");
        printf("clear              Clear vector storage\n");
        printf("list               List stored vectors\n");
        printf("load <fname>       Load vectors from a CSV file\n");
        printf("save <fname>       Save vectors to a CSV file\n");
        printf("quit               Exit the program\n");

        return 0;
    }

    initializeStorage(&storage);
    runUI(&storage);
    clearStorage(&storage);

    return 0;
}