/**
 * Author: Joshua Simon
 * Date: 9/29/2026
 * Description: the h file that declares the vector struct and math functions
 **/

#ifndef LAB5_VECTOR_H
#define LAB5_VECTOR_H

struct vector {
    char name;
    double x, y, z;
};

struct vector vectorAdd(struct vector a, struct vector b);
struct vector vectorSub(struct vector a, struct vector b);
struct vector vectorMultiply(struct vector a, double scalar);


#endif //LAB5_VECTOR_H
