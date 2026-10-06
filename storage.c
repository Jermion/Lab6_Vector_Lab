/**
 * Author: Joshua Simon
 * Date: 9/29/2026
 * Description: the storage.c file that initializes the methods inside of storage.h
 **/

#include "storage.h"

void initializeStorage(struct storage *storage) {
    storage->count = 0;
}

int addVector(struct storage *storage, struct vector newVector) {
    int i;

    for (i=0; i < storage->count; i++) {
        if (storage->vectors[i].name == newVector.name) {
            storage->vectors[i] = newVector;
            return 0;
        }
    }

    if (storage->count < maxStorage) {
        storage->vectors[storage->count] = newVector;
        storage->count++;
        return 0;
    } else {
        // Storage is full
        return 1;
    }
}

int findVector(struct storage *storage, char name, struct vector *result) {
    int i;

    for (i=0; i < storage->count; i++) {
        if (name == storage->vectors[i].name) {
            *result = storage->vectors[i];
            return 0;
        }
    }
    return 1;
}

// Setting the count to 0, indicating 0 valid vectors stored
void clearStorage(struct storage *storage) {
    storage->count = 0;
}