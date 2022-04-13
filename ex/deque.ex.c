#include "../src/deque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Construct a new deque struct */
StructDeque(MyDeque, int, INT32_MIN);

/** Creating a deque of custom struct */
typedef struct {
    double x;
    double y;
} Point;
StructDeque(Points, Point, ((Point){0.0 / 0.0, 0.0 / 0.0}));  // Point deque, fallback (nan, nan)

int main() {
    MyDeque* deque = create_MyDeque();
    DequeInspect(deque, "%d");

    printf("unshift: 1, 2, 3");
    deque->unshift(deque, 1);
    deque->unshift(deque, 2);
    deque->unshift(deque, 3);
    DequeInspect(deque, "%d");

    printf("push: 4, 5, 6");
    deque->push(deque, 4);
    deque->push(deque, 5);
    deque->push(deque, 6);
    DequeInspect(deque, "%d");

    printf("reverse");
    deque->reverse(deque);
    DequeInspect(deque, "%d");

    MyDeque* deque2 = create_MyDeque();
    deque2->push(deque2, 11);
    deque2->push(deque2, 22);
    deque2->push(deque2, 33);
    deque2->push(deque2, 44);
    deque2->push(deque2, 55);
    deque2->push(deque2, 66);
    DequeInspect(deque2, "%d");

    printf("concat");
    deque->concat(deque, deque2);
    DequeInspect(deque, "%d");
    DequeInspect(deque2, "%d");

    printf("shift: %d\n", deque->shift(deque));
    printf("pop: %d", deque->pop(deque));
    DequeInspect(deque, "%d");

    printf("shift: %d", deque->shift(deque));
    DequeInspect(deque, "%d");

    printf("shift: %d", deque->shift(deque));
    DequeInspect(deque, "%d");

    printf("pop: %d", deque->pop(deque));
    DequeInspect(deque, "%d");

    printf("pop: %d", deque->pop(deque));
    DequeInspect(deque, "%d");

    deque->free(deque);

    Points* points = create_Points();
    DequeInspect(points, "%f, %f");

    points->unshift(points, ((Point){1.0, 2.0}));
    points->unshift(points, ((Point){3.0, 4.0}));
    points->unshift(points, ((Point){5.0, 6.0}));
    DequeInspect(points, "%f, %f");

    points->push(points, ((Point){7.0, 8.0}));
    points->push(points, ((Point){9.0, 10.0}));
    points->push(points, ((Point){11.0, 12.0}));
    DequeInspect(points, "%f, %f");

    Point point = points->shift(points);
    printf("shift: %f, %f", point.x, point.y);
    DequeInspect(points, "%f, %f");

    while (points->size) {
        point = points->pop(points);
        printf("pop: %f, %f", point.x, point.y);
        DequeInspect(points, "%f, %f");
    }

    points->free(points);

    return 0;
}
