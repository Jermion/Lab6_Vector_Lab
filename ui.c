/**
 * Author: Joshua Simon
 * Date: 10/12/2026
 * Description: Handles the user interface for the vector calculator
**/


#include <stdio.h>
#include <string.h>
#include "ui.h"

void printVector(struct vector vect) {
    printf("%c = %.2f %.2f %.2f\n", vect.name, vect.x, vect.y, vect.z);
}

void printAnswer(struct vector vect) {
    printf("ans = %.2f %.2f %.2f\n", vect.x, vect.y, vect.z);
}

void runUI(struct storage *storage) {
    char input[100];
    char name;
    char firstName;
    char secondName;
    char resultName;
    char operator;
    char extra;

    double x;
    double y;
    double z;
    double scalar;

    int i;

    struct vector firstVector;
    struct vector secondVector;
    struct vector resultVector;
    struct vector newVector;

    while (1) {
        printf("minimat> ");

        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        // Loading vectors from a CSV file:
        if (strncmp(input, "load ", 5) == 0) {
            char filename[100];
            char line[256];
            FILE *file;
            int lineNumber = 0;

            if (sscanf(input + 5, "%99s %c", filename, &extra) != 1) {
                printf("Invalid filename found.\n");
                continue;
            }

            file = fopen(filename, "r");

            if (file == NULL) {
                printf("File could not be opened.\n");
                continue;
            }

            while (fgets(line, sizeof(line), file) != NULL) {
                lineNumber++;

                // If an empty line was detected, skip it
                if (strspn(line, " \t\r\n") == strlen(line)) {
                    continue;
                }

                // Extract vector information
                if (sscanf(line, " %c , %lf , %lf , %lf %c",
                           &newVector.name, &newVector.x, &newVector.y, &newVector.z, &extra) != 4) {
                    printf("Invalid CSV format on line %d.\n", lineNumber);
                    continue;
                }

                if (addVector(storage, newVector) == 1) {
                    printf("Memory allocation failed.\n");
                    break;
                }

                printVector(newVector);
            }

            fclose(file);
            continue;
        }


        // Saving vectors to a CSV file
        if (strncmp(input, "save ", 5) == 0) {
            char filename[100];
            FILE *file;
            int writeFailed = 0;

            if (sscanf(input + 5, "%99s %c", filename, &extra) != 1) {
                printf("Invalid filename found.\n");
                continue;
            }

            file = fopen(filename, "w");

            if (file == NULL) {
                printf("File could not be opened.\n");
                continue;
            }

            // Write all stored vectors to the CSV file
            for (i = 0; i < storage->count; i++) {
                struct vector vect = storage->vectors[i];

                if (fprintf(file, "%c,%.17g,%.17g,%.17g\n",
                            vect.name, vect.x, vect.y, vect.z) < 0) {
                    writeFailed = 1;
                    break;
                }
            }

            if (fclose(file) != 0) {
                writeFailed = 1;
            }

            if (writeFailed) {
                printf("Error saving file.\n");
            } else {
                printf("Saved %d vectors to %s.\n",
                       storage->count, filename);
            }

            continue;
        }


        // Replacing commas with spaces:
        for (i = 0; input[i] != '\0'; i++) {
            if (input[i] == ',') {
                input[i] = ' ';
            }
        }

        // If user enters 'quit', exit program
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // If the user enters 'clear', clear the storage
        if (strcmp(input, "clear") == 0) {
            clearStorage(storage);
            continue;
        }

        // If the user enters 'list', list the vectors in storage
        if (strcmp(input, "list") == 0) {
            for (i = 0; i < storage->count; i++) {
                printVector(storage->vectors[i]);
            }
            continue;
        }

        // If the user enters numbers, assume they are entering vector values
        if (sscanf(input, " %c = %lf %lf %lf %c", &name, &x, &y, &z, &extra) == 4) {
            newVector.name = name;
            newVector.x = x;
            newVector.y = y;
            newVector.z = z;

            // Check if memory allocation failed
            if (addVector(storage, newVector) == 1) {
                printf("Memory allocation failed.\n");
            } else {
                printVector(newVector);
            }
            continue;
        }

        // Checking for the add and subtract operators, but if the
        // name of the vectors do not exist, notify user
        if (sscanf(input, " %c = %c %c %c %c", &resultName, &firstName, &operator, &secondName, &extra) == 4 &&
            (operator == '+' || operator == '-')) {
            if (findVector(storage, firstName, &firstVector) == 1 || findVector(storage, secondName, &secondVector) ==
                1) {
                printf("Vector does not exist within storage.\n");
                continue;
            }

            // After checking for faulty inputs, now begin the arithmetic
            if (operator == '+') {
                resultVector = vectorAdd(firstVector, secondVector);
            } else {
                resultVector = vectorSub(firstVector, secondVector);
            }

            resultVector.name = resultName;

            if (addVector(storage, resultVector) == 1) {
                printf("Memory allocation failed.\n");
                continue;
            }

            printVector(resultVector);
            continue;
        }

        // The Math for multiplying a vector by a scalar
        if (sscanf(input, " %c = %c * %lf %c", &resultName, &firstName, &scalar, &extra) == 3) {
            if (findVector(storage, firstName, &firstVector) == 1) {
                printf("Vector does not exist.\n");
                continue;
            }
            resultVector = vectorMultiply(firstVector, scalar);
            resultVector.name = resultName;

            if (addVector(storage, resultVector) == 1) {
                printf("Memory allocation failed.\n");
                continue;
            }

            printVector(resultVector);
            continue;
        }

        // The math for multiplying a scalar by a vector
        if (sscanf(input, " %c = %lf * %c %c", &resultName, &scalar, &firstName, &extra) == 3) {
            if (findVector(storage, firstName, &firstVector) == 1) {
                printf("Vector does not exist.\n");
                continue;
            }
            resultVector = vectorMultiply(firstVector, scalar);
            resultVector.name = resultName;

            if (addVector(storage, resultVector) == 1) {
                printf("Memory allocation failed.\n");
                continue;
            }

            printVector(resultVector);
            continue;
        }

        // Catching some input cases for addition and subtraction
        if (sscanf(input, " %c %c %c %c", &firstName, &operator, &secondName, &extra) == 3 &&
            (operator == '+' || operator == '-')) {
            if (findVector(storage, firstName, &firstVector) == 1 || findVector(storage, secondName, &secondVector) ==
                1) {
                printf("Vector does not exist within storage.\n");
                continue;
            }

            // After checking for faulty inputs, now begin the arithmetic
            if (operator == '+') {
                resultVector = vectorAdd(firstVector, secondVector);
            } else {
                resultVector = vectorSub(firstVector, secondVector);
            }
            printAnswer(resultVector);
            continue;
        }

        // Catching different input for multiplying vector and scalar
        if (sscanf(input, " %lf * %c %c", &scalar, &firstName, &extra) == 2) {
            if (findVector(storage, firstName, &firstVector) == 1) {
                printf("Vector does not exist.\n");
                continue;
            }
            resultVector = vectorMultiply(firstVector, scalar);
            printAnswer(resultVector);
            continue;
        }
        if (sscanf(input, " %c * %lf %c", &firstName, &scalar, &extra) == 2) {
            if (findVector(storage, firstName, &firstVector) == 1) {
                printf("Vector does not exist.\n");
                continue;
            }
            resultVector = vectorMultiply(firstVector, scalar);
            printAnswer(resultVector);
            continue;
        }

        // Search for vector given name
        if (sscanf(input, " %c %c", &name, &extra) == 1) {
            if (findVector(storage, name, &resultVector) == 0) {
                printVector(resultVector);
            } else {
                printf("Vector does not exist.\n");
            }
            continue;
        }
        // If no user input matches, print invalid
        printf("Invalid Command\n");
    }
}
