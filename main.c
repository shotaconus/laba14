#include <stdio.h>
#include <stdint.h>
#include "vector.h"

int main() {
    Vector v = createVector(8);

    reserve(&v, SIZE_MAX);


    return 0;
}
