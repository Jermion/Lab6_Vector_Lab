
/**
 * Author: Joshua Simon
 * Date: 9/29/2026
 * Description: the storage.c file that initializes the methods inside of storage.h
 **/

#include <stdlib.h>
#include "storage.h"

// Initialize the storage with no allocated memory or stored vectors
void initializeStorage(struct storage *storage) {
    storage->vectors = NULL;
    storage->count = 0;
    storage->capacity = 0;
}

// Add a new vector or replace an existing vector with the same name
int addVector(struct storage *storage, struct vector newVector) {
    int i;

    // For loop for checking if a vector shares a name
    for (i = 0; i < storage->count; i++) {
        if (storage->vectors[i].name == newVector.name) {
            storage->vectors[i] = newVector;
            return 0;
        }
    }
    // Checking if more memory needs to be reallocated
    if (storage->count == storage->capacity) {
        int newCapacity;
        struct vector *temp;

        // Originally enough space for 4 vectors, if more are needed, multiply by 2
        if (storage->capacity == 0) {
            newCapacity = 4;
        } else {
            newCapacity = storage->capacity * 2;
        }

        /*
         * How realloc() is working here:
         * realloc(NULL, size) works like malloc(), allocating memory on the heap.
         * It returns a pointer to the allocated memory, which is stored in temp.
         * When the array reaches capacity, realloc() expands the memory
         * and may move it to a new location.
         * temp is used so the original pointer is not lost if realloc() fails.
         * storage->vectors will then point to the allocated array.
         */
        temp = realloc(storage->vectors, newCapacity * sizeof(struct vector));

        // If the allocation fails, leave the original memory unchanged
        if (temp == NULL) {
            return 1;
        }

        // Update the pointer to the allocated memory and its capacity
        // Temp is being assigned to storage->vectors to preserve the memory address, which allows the program to
        // use free(storage->vector) to release the memory at the user request.
        storage->vectors = temp;
        storage->capacity = newCapacity;
    }

    // Store the new vector in the next available position
    storage->vectors[storage->count] = newVector;
    storage->count++;

    return 0;
}

// Search for a vector by its name
int findVector(struct storage *storage, char name, struct vector *result) {
    int i;

    // Loop through all currently stored vectors
    for (i = 0; i < storage->count; i++) {
        if (name == storage->vectors[i].name) {
            *result = storage->vectors[i]; // Copy the found vector into result
            return 0;
        }
    }

    // If no matching vector was found, return 1
    return 1;
}

// Free the allocated memory and reset the storage
void clearStorage(struct storage *storage) {
    free(storage->vectors);
    storage->vectors = NULL;
    storage->count = 0;
    storage->capacity = 0;
}
