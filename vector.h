//
// Created by NIkita on 15.04.2023.
//

#ifndef LABA14_VECTOR_H
#define LABA14_VECTOR_H

#include <stdio.h>
typedef struct Vector {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector createVector(size_t n);

void reserve(Vector *v, size_t newCapacity);

void clear(Vector *v);

void shrinkToFit(Vector *v);

#endif //LABA14_VECTOR_H
