# DEQUE

Double Ended QUEue (deque) implementation using C++ programming language.

## Information

`deque` (usually pronounced like `"deck"`) is an irregular acronym of double-ended queue. Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).

`deque` in our library is implemented such as `linked list`, where element of `linked list` is `dynamic array`.

## Member functions

- `(constructor)` - construct deque container
- `(destructor)` - destructor deque container

### Capacity

- `size` - get size of deque container
- `empty` - test whether container is empty

### Element access

- `operator[]` - access element
- `at` - access element (if element is not exist then throwing an `out_of_range` exception)

### Modifiers

- `push_back` - add element at the end
- `push_front` - add element at the front
- `pop_back` -  delete last element
- `pop_front` - delete first element
- `insert` - insert element to specific position
- `erase` - remove element from specific position
- `clear` - remove all elements

## To run unit tests

1. Download [CMake](https://cmake.org/download/)
2. Run unit tests
    - build unit tests

        ```bash
        cmake -B ./build
        cmake --build ./build
        ```

    - run unit tests

        ```bash
        ./build/UNIT_TESTS
        ```
