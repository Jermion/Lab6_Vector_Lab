/**
 * Author: Joshua Simon
 * Date: 9/29/2026
 * Description: the storage.h file that will handle vector storage
 **/

#ifndef LAB5_STORAGE_H
#define LAB5_STORAGE_H
#include "vector.h"
#define maxStorage 10

struct storage {
    struct vector vectors[maxStorage];
    int count;
};

void initializeStorage(struct storage *storage);

int addVector(struct storage *storage, struct vector newVector);

int findVector(struct storage *storage, char name, struct vector *result);

void clearStorage(struct storage *storage);

#endif //LAB5_STORAGE_H
