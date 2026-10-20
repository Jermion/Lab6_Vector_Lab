/**
 * Author: Joshua Simon
 * Date: 9/29/2026
 * Description: the storage.h file that will handle vector storage
 **/

#ifndef LAB5_STORAGE_H
#define LAB5_STORAGE_H
#include "vector.h"

struct storage {
    struct vector *vectors;
    int count;
    int capacity;
};// Initializes the storage struct

void initializeStorage(struct storage *storage);

// Adds the vector to
int addVector(struct storage *storage, struct vector newVector);

int findVector(struct storage *storage, char name, struct vector *result);

void clearStorage(struct storage *storage);

#endif //LAB5_STORAGE_H
