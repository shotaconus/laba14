#include <stdio.h>
#include <stdint.h>
#include "vector.h"
#include <assert.h>

void test_popBack_notEmptyVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    Vector v = createVector(2);
    pushBack(&v, 42);
    assert(atVector(&v, 0) == &v.data[0]);
}

int main() {

    test_popBack_notEmptyVector();

    test_atVector_notEmptyVector();

    return 0;
}
