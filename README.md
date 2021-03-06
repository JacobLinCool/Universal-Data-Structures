<div align="center">

# Universal Data Structures

Lightweight implementation of generic and powerful data structures in C.

[vector](#vectorh) ·
[map](#maph) ·
[set](#seth) ·
[queue](#queueh) ·
[stack](#stackh) ·
[deque](#dequeh)

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

- `void vec->push(vec, elm)`: _**`O(1)`**_ add an element to the end of the vector `vec`
- `_type vec->pop(vec)`: _**`O(1)`**_ remove and return the last element of the vector `vec`
- `_type vec->back(vec)`: _**`O(1)`**_ get the last element of the vector `vec`
- `void vec->unshift(vec, elm)`: _**`O(n)`**_ add an element to the beginning of the vector `vec`
- `_type vec->shift(vec)`: _**`O(n)`**_ remove and return the first element of the vector `vec`
- `_type vec->front(vec)`: _**`O(1)`**_ get the first element of the vector `vec`
- `void vec->insert(vec, idx, elm)`: _**`O(n)`**_ insert an element at `idx` of the vector `vec`
- `_type vec->remove(vec, idx)`: _**`O(n)`**_ remove and return the element at `idx` of the vector `vec`
- `void vec->set(vec, idx, elm)`: _**`O(1)`**_ set the element at `idx` of the vector `vec` to `elm`
- `_type vec->get(vec, idx)`: _**`O(1)`**_ get the element at `idx` of the vector `vec`
- `void vec->clear(vec)`: _**`O(1)`**_ remove all elements from the vector `vec`
- `void vec->free(vec)`: _**`O(1)`**_ free the vector `vec`

#### utilities

You can use `VectorInspect` to inspect a vector.

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

You can make `deque` to behave like a `queue` by using `unshift` and `shift`.

### `stack.h`

_**Not Implemented Yet. [Any Contribution is Welcome!](./CONTRIBUTING.md)**_

You can make `deque` to behave like a `stack` by using `push` and `pop`.

### [`deque.h`](./src/deque.h)

Double-ended queue of any type, implemented with _`XOR List`_.

```c
/** Construct a new deque struct */
StructDeque(_name, _type, _fallback);
/** Example: */
StructDeque(MyDeque, int, INT32_MIN);
```

#### constructor

Create an instance of a defined deque struct.

```c
MyDeque* deque = create_MyDeque();
```

#### properties

- `deque->head`: the head node of underlying xor-list
- `deque->tail`: the tail node of underlying xor-list
- `deque->size`: the number of elements in the deque `deque`

#### methods

- `void deque->push(deque, elm)`: _**`O(1)`**_ add an element to the end of the deque `deque`
- `void deque->unshift(deque, elm)`: _**`O(1)`**_ add an element to the beginning of the deque `deque`
- `_type deque->pop(deque)`: _**`O(1)`**_ remove and return the last element of the deque `deque`
- `_type deque->shift(deque)`: _**`O(1)`**_ remove and return the first element of the deque `deque`
- `_type deque->back(deque)`: _**`O(1)`**_ get the last element of the deque `deque`
- `_type deque->front(deque)`: _**`O(1)`**_ get the first element of the deque `deque`
- `void deque->reverse(deque)`: _**`O(1)`**_ reverse the order of the elements in the deque `deque`
- `void deque->concat(deque, other)`: _**`O(1)`**_ concatenate the elements of the deque `other` to the end of the deque `deque`, this method will remove all elements in `other`, but not free `other`
- `void deque->clear(deque)`: _**`O(n)`**_ remove all elements from the deque `deque`
- `void deque->free(deque)`: _**`O(n)`**_ free the deque `deque`

#### utilities

You can use `DequeInspect` to inspect a deque.

```c
/** Inspect the deque "deque" with print format "%d" */
DequeInspect(deque, "%d");
```

#### example

See [deque.ex.c](./ex/deque.ex.c).

### [`xor-list.h`](./src/xor-list.h)

Memory efficient doubly linked list of any type.

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

- `_name* node->xor(node_a, node_b)`: _**`O(1)`**_ get the xor of the node `node_a` and `node_b`
- `_name* node->left(node, right)`: _**`O(1)`**_ get the left node of the node `node`
- `_name* node->right(node, left)`: _**`O(1)`**_ get the right node of the node `node`
- `void node->insert(node, left, right)`: _**`O(1)`**_ insert the node `node` between `left` and `right`
- `void node->remove(node, adjacent)`: _**`O(1)`**_ remove the node `node` by giving one of its adjacent nodes `adjacent`
- `size_t node->traverse(node, next, func)`: _**`O(n)`**_ traverse the list from `node` and `next` is the direction. `func` is the callback function for each node
- `void node->free(node)`: _**`O(1)`**_ free the node `node`

#### utilities

There are no utilities for `xor-list`.

#### example

See [xor-list.ex.c](./ex/xor-list.ex.c).
