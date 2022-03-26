#include "../src/deque.h"
#include <stdlib.h>
#include <assert.h>

StructDeque(IntDeq, int, INT32_MIN);

void test_front(int size);
void test_back(int size);
void test_reverse(int size);
void test_concat(int a_size, int b_size);

int main() {
    for (int i = 0; i < 10; i++) {
        test_front(i);
        test_back(i);
        test_reverse(i);

        for (int j = 0; j < 10; j++) {
            test_concat(i, j);
        }
    }

    return 0;
}

void test_front(int size) {
    IntDeq* deq = create_IntDeq();

    for (int i = 0; i < size; i++) {
        deq->unshift(deq, i);
        assert(deq->front(deq) == i);
    }

    for (int i = size - 1; i >= 0; i--) {
        assert(deq->front(deq) == i);
        assert(deq->shift(deq) == i);
    }

    assert(deq->front(deq) == INT32_MIN);
    assert(deq->shift(deq) == INT32_MIN);
    assert(deq->size == 0);

    deq->free(deq);
}

void test_back(int size) {
    IntDeq* deq = create_IntDeq();

    for (int i = 0; i < size; i++) {
        deq->push(deq, i);
        assert(deq->back(deq) == i);
    }

    for (int i = size - 1; i >= 0; i--) {
        assert(deq->back(deq) == i);
        assert(deq->pop(deq) == i);
    }

    assert(deq->back(deq) == INT32_MIN);
    assert(deq->pop(deq) == INT32_MIN);
    assert(deq->size == 0);

    deq->free(deq);
}

void test_reverse(int size) {
    IntDeq* deq = create_IntDeq();

    for (int i = 1; i <= size; i++) {
        deq->push(deq, i);
    }

    deq->reverse(deq);

    for (int i = size; i >= 1; i--) {
        assert(deq->front(deq) == i);
        assert(deq->shift(deq) == i);
    }

    assert(deq->front(deq) == INT32_MIN);
    assert(deq->shift(deq) == INT32_MIN);
    assert(deq->size == 0);

    deq->free(deq);
}

void test_concat(int a_size, int b_size) {
    IntDeq* a = create_IntDeq();
    IntDeq* b = create_IntDeq();
    for (int i = 1; i <= a_size; i++) {
        a->push(a, i);
    }
    for (int i = 1; i <= b_size; i++) {
        b->push(b, i);
    }

    a->concat(a, b);

    assert(a->size == a_size + b_size);
    assert(b->size == 0);
    assert(a->back(a) == ((a_size + b_size) ? (b_size ? b_size : a_size) : INT32_MIN));
    assert(a->front(a) == ((a_size + b_size) ? 1 : INT32_MIN));
    assert(b->back(b) == INT32_MIN);
    assert(b->front(b) == INT32_MIN);

    for (int i = 1; i <= a_size; i++) {
        assert(a->shift(a) == i);
    }
    for (int i = 1; i <= b_size; i++) {
        assert(a->shift(a) == i);
    }

    a->free(a);
    b->free(b);
}
