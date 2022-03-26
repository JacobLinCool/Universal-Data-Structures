<div align="center">

# Universal Data Structures

Lightweight implementation of generic and powerful data structures in C.

[vector](#vectorh) ·
[map](#maph) ·
[set](#seth) ·
[queue](#queueh) ·
[stack](#stackh)

[xor list](#xor-listh)

</div>

## Usage

They are just header files.

You can directly include them in your project (or paste them in your code).

## Features

### [`vector.h`](./src/vector.h)

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

#### utilities

You can use `VectorInspect` to inspect the vector.

```c
/** Inspect the vector "vec" with print format "%d" */
VectorInspect(vec, "%d");
```

#### example

See [vector.ex.c](./ex/vector.ex.c).

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

### [`xor-list.h`](./src/xor-list.h)

Memory efficient doubly linked list for any type.

```c
/** Construct a new XOR list node struct */
StructXORListNode(_name, _type);
/** Example: */
StructXORListNode(MyNode, int);
```

#### constructor

Create a node of a defined XOR list node struct.

```c
MyNode* node = create_Node(123);
```

#### properties

- `node->val`: the value of the node `node`
- `node->beacon`: the pointer "beacon" of the node `node`

> pointer beacon: the xor result of the previous and next node address

#### methods

- `_name* node->xor(node_a, node_b)`: get the xor of the node `node_a` and `node_b`
- `_name* node->left(node, right)`: get the left node of the node `node`
- `_name* node->right(node, left)`: get the right node of the node `node`
- `void node->insert(node, left, right)`: insert the node `node` between `left` and `right`
- `void node->remove(node, adjacent)`: remove the node `node` by giving one of its adjacent nodes `adjacent`
- `_name* node->find(node, next, val)`: find the node with value `val`, start from `node` and `next` is the direction
- `size_t node->traverse(node, next, func)`: traverse the list from `node` and `next` is the direction. `func` is the callback function for each node
- `void node->free(node)`: free the node `node`

#### utilities

There are no utilities for `xor-list`.

#### example

See [xor-list.ex.c](./ex/xor-list.ex.c).
