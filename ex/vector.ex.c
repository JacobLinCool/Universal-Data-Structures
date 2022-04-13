#include "../src/vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Construct a new vector struct */
StructVector(IntVector, int, INT32_MIN);
// ^ Create an "int" vector named "IntVector" with fallback value INT32_MIN

/** Shorthands for creating a new vector struct */
SV(StringVector, char*, NULL);    // NULL is the fallback value
SV(VectorPtrVector, IntVector*);  // NULL (0) is the default fallback value

/** Creating a Vector of custom struct */
typedef struct {
    double x;
    double y;
} Point;
Point fallback_point = {0.0 / 0.0, 0.0 / 0.0};     // NaN point
StructVector(PointVector, Point, fallback_point);  // A Point vector fallback with fallback_point

int main() {
    IntVector* int_vec = create_IntVector();

    for (int i = 1; i <= 100; i++) {
        int_vec->push(int_vec, i * i);
        printf("[Push %d] Capacity = %zu, Size = %zu\n", i * i, int_vec->capacity, int_vec->size);
    }

    // Print the contents of the vector
    VectorInspect(int_vec, "%d");

    for (int i = 1; i <= 100; i++) {
        int popped = int_vec->pop(int_vec);
        printf("[Pop %d] Capacity = %zu, Size = %zu\n", popped, int_vec->capacity, int_vec->size);
    }

    int_vec->free(int_vec);

    StringVector* strings = create_StringVector();
    strings->push(strings, strdup("Hello"));  // strdup() makes a copy of the string in heap
    strings->push(strings, strdup("World"));  // so we can free it later
    strings->push(strings, strdup("!"));

    VectorInspect(strings, "%s");
    VectorInspect(strings, "%p");

    while (strings->size > 0) {
        free(strings->pop(strings));
    }
    strings->free(strings);

    PointVector* points = create_PointVector();
    points->push(points, (Point){1.0, 2.0});
    points->push(points, (Point){3.0, 4.0});
    points->push(points, (Point){5.0, 6.0});

    VectorInspect(points, "%f, %f");

    for (int i = 0; i < points->size; i++) {
        printf("[Point %d] x = %lf, y = %lf\n", i, points->get(points, i).x,
               points->get(points, i).y);
    }

    while (points->size > 0) {
        points->shift(points);
    }

    points->free(points);
}
