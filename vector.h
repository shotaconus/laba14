//
// Created by NIkita on 15.04.2023.
//

#ifndef LABA14_VECTOR_H
#define LABA14_VECTOR_H

#include <stdio.h>
#include <stdbool.h>
typedef struct Vector {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector createVector(size_t n);

void reserve(Vector *v, size_t newCapacity);

void clear(Vector *v);

void shrinkToFit(Vector *v);

void deleteVector(Vector *v);

bool isEmpty(Vector *v);

bool isFull(Vector *v);

int getVectorValue(Vector *v, size_t i);

void pushBack(Vector *v, int x);

void popBack(Vector *v);

int* atVector(Vector *v, size_t index);


#endif //LABA14_VECTOR_H