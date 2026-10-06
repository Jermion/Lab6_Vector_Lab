/**
 * Author: Joshua Simon
 * Date: 9/29/2026
 * Description: the c file that initializes the vector.h methods
 **/

#include "vector.h"

struct vector vectorAdd(struct vector a, struct vector b) {
    double newX = (a.x + b.x);
    double newY = (a.y + b.y);
    double newZ = (a.z + b.z);

    struct vector resultVector;
    resultVector.x = newX;
    resultVector.y = newY;
    resultVector.z = newZ;

    return resultVector;
}

struct vector vectorSub(struct vector a, struct vector b) {
    double newX = (a.x - b.x);
    double newY = (a.y - b.y);
    double newZ = (a.z - b.z);

    struct vector resultVector;
    resultVector.x = newX;
    resultVector.y = newY;
    resultVector.z = newZ;

    return resultVector;
}

struct vector vectorMultiply(struct vector a, double scalar) {
    double newX = (a.x * scalar);
    double newY = (a.y * scalar);
    double newZ = (a.z * scalar);

    struct vector resultVector;
    resultVector.x = newX;
    resultVector.y = newY;
    resultVector.z = newZ;

    return resultVector;
}


