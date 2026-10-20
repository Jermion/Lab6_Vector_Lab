/**
 * Author: Joshua Simon
 * Date: 9/29/2026
 * Description: the h file that declares the vector struct and math functions
 **/

#ifndef LAB5_VECTOR_H
#define LAB5_VECTOR_H
// Struct used to represent a 3D vector
struct vector {
    char name;
    double x, y, z;
};

// Adds two vectors and returns the resulting vector
struct vector vectorAdd(struct vector a, struct vector b);

// Subtracts vector b from vector a and returns the resulting vector
struct vector vectorSub(struct vector a, struct vector b);

// Multiplies a vector by a scalar and returns the resulting veco
struct vector vectorMultiply(struct vector a, double scalar);


#endif //LAB5_VECTOR_H
