/**
 * Author: Joshua Simon
 * Date: 9/29/2026
 * Description: the c file that initializes the vector.h methods
 **/

#include "vector.h"

// Adds the x, y, and z components of two vectors
struct vector vectorAdd(struct vector a, struct vector b) {
    double newX = (a.x + b.x);
    double newY = (a.y + b.y);
    double newZ = (a.z + b.z);

    // Assigning the new components to the result vector
    struct vector resultVector;
    resultVector.x = newX;
    resultVector.y = newY;
    resultVector.z = newZ;

    return resultVector;
}
// Subtracts the components of vector b from vector a
struct vector vectorSub(struct vector a, struct vector b) {
    double newX = (a.x - b.x);
    double newY = (a.y - b.y);
    double newZ = (a.z - b.z);

    // Assigning the new components to the result vecto
    struct vector resultVector;
    resultVector.x = newX;
    resultVector.y = newY;
    resultVector.z = newZ;

    return resultVector;
}

// Multiplying the components of vector a by a scalar
struct vector vectorMultiply(struct vector a, double scalar) {
    double newX = (a.x * scalar);
    double newY = (a.y * scalar);
    double newZ = (a.z * scalar);

// Assigning the new components to the result vector
    struct vector resultVector;
    resultVector.x = newX;
    resultVector.y = newY;
    resultVector.z = newZ;

    return resultVector;
}


