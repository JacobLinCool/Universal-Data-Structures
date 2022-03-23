<div align="center">

# Universal Data Structures

Lightweight implementation of generic and powerful data structures in C.

[vector](#vectorh) ·
[map](#maph) ·
[set](#seth) ·
[queue](#queueh) ·
[stack](#stackh)

</div>

## Usage

They are just header files.

You can directly include them in your project (or paste them in your code).

## Features

### [`vector.h`](./vector.h)

Auto-managed dynamic array of any type.

```c
/** Construct a new vector struct */
StructVector(_name, _type, _fallback);
/** Example: */
StructVector(MyVector, int, INT32_MIN);
```

#### constructor

Create an instance of a defined vector struct.

```c
MyVector* vec = create_MyVector();
```

#### properties

- `vec->size`: the number of elements in the vector `vec`
- `vec->capacity`: the current capacity of the vector `vec`

#### methods

- `void vec->push(vec, elm)`: add an element to the end of the vector `vec`
- `_type vec->pop(vec)`: remove and return the last element of the vector `vec`
- `_type vec->back(vec)`: get the last element of the vector `vec`
- `void vec->unshift(vec, elm)`: add an element to the beginning of the vector `vec`
- `_type vec->shift(vec)`: remove and return the first element of the vector `vec`
- `_type vec->front(vec)`: get the first element of the vector `vec`
- `void vec->insert(vec, idx, elm)`: insert an element at `idx` of the vector `vec`
- `_type vec->remove(vec, idx)`: remove and return the element at `idx` of the vector `vec`
- `void vec->set(vec, idx, elm)`: set the element at `idx` of the vector `vec` to `elm`
- `_type vec->get(vec, idx)`: get the element at `idx` of the vector `vec`
- `void vec->clear(vec)`: remove all elements from the vector `vec`
- `void vec->free(vec)`: free the vector `vec`

#### inspector

You can use `VectorInspect` to inspect the vector.

```c
/** Inspect the vector "vec" with print format "%d" */
VectorInspect(vec, "%d");
```

#### example

See [vector.ex.c](./vector.ex.c).

### `map.h`

_**Not Implemented Yet. [Any Contribution is Welcome!](./CONTRIBUTING.md)**_

### `set.h`

_**Not Implemented Yet. [Any Contribution is Welcome!](./CONTRIBUTING.md)**_

### `queue.h`

_**Not Implemented Yet. [Any Contribution is Welcome!](./CONTRIBUTING.md)**_

You can make `vector` to behave like a `queue` by using `unshift` and `shift`.

### `stack.h`

_**Not Implemented Yet. [Any Contribution is Welcome!](./CONTRIBUTING.md)**_

You can make `vector` to behave like a `stack` by using `push` and `pop`.
