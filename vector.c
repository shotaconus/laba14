#include "vector.h"
#include <stdbool.h>
#include <malloc.h>

Vector createVector(size_t n) {
    Vector a;
    a.size = n;
    if (!malloc(n * sizeof(int))) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        a.data = calloc(n, sizeof(int));
        a.capacity = n;
        a.size = 0;

        return a;
    }
}

void reserve(Vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    } else if (newCapacity < v->size) {
        realloc(v->data, newCapacity * sizeof(int));
        v->size = newCapacity;
        v->capacity = newCapacity;
    } else {
        if (malloc(newCapacity * sizeof(int)) == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        } else {
            realloc(v->data, newCapacity * sizeof(int));
            v->capacity = newCapacity;
        }
    }
}

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    for (int i = v->size - 1; i < v->capacity; i++)
        free(&v->data[i]);

    v->capacity = v->size;
}

void deleteVector(Vector *v) {
    free(v->data);
}

bool isEmpty(Vector *v) {
    return v->size == 0;
}

bool isFull(Vector *v) {
    return v->size == v->capacity ? true : false;
}

int getVectorValue(Vector *v, size_t i) {
    return v->data[i];
}

void pushBack(Vector *v, int x) {
    if (isFull(v)) {
        reserve(v, v->capacity + 1);
    } else if (isEmpty(v)) {
        createVector(1);
    }
    v->data[v->size] = x;
    v->size += 1;
}

void popBack(Vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        v->size--;
    }
}
