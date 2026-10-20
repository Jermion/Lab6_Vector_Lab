/**
 * Author: Joshua Simon
 * Date: 9/29/2026
 * Description: the storage.c file that initializes the methods inside of storage.h
 **/

#include <stdlib.h>
#include "storage.h"

void initializeStorage(struct storage *storage) {
    storage->vectors = NULL;
    storage->count = 0;
    storage->capacity = 0;
}

int addVector(struct storage *storage, struct vector newVector) {
    int i;

    for (i=0; i < storage->count; i++) {
        if (storage->vectors[i].name == newVector.name) {
            storage->vectors[i] = newVector;
            return 0;
        }
    }

   if (storage->count == storage->capacity) {
       int newCapacity;
       struct vector *temp;

       if (storage->capacity == 0) {
           newCapacity = 4;
       } else {
           newCapacity = storage->capacity * 2;
       }

       temp = realloc(storage->vectors, newCapacity * sizeof(struct vector));

       if (temp == NULL) {
           return 1;
       }

       storage->vectors = temp;
       storage->capacity = newCapacity;
   }
    storage->vectors[storage->count] = newVector;
    storage->count++;
    return 0;
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
    free(storage->vectors);
    storage->vectors = NULL;
    storage->count = 0;
    storage->capacity = 0;
}