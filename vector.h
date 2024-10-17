#ifndef VECTOR_H_   
#define VECTOR_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct {
  size_t capacity; // maximum number of elements the vector can contain
  size_t num_elems; // current number of elements in the vector
  int* elems; // pointer to the underlying array
} vector;

typedef struct {
  const vector* vec; // pointer to the underlying vector
  size_t ix; // current index
} vector_iterator;

// 2p
/**
  Creates a vector from an array. Note, that the vector does not use the array directly, it copies its elements to a
  new memory location, and uses that. This means that `p` is guaranteed to be different from `elems`.

  Params:
    - p: pointer to an array
    - size: number of elements to initialize the vector with (also sets capacity)
*/
vector* mk_vector(int* p, size_t size);

// 1p
/**
  Frees the memory allocated by the underlying array and the vector struct.
  Calling any operations on the vector after `free_vector` has undefined behaviour.
*/
void free_vector(vector* v);

// 2p
/**
  Resizes the capacity of a vector. If the current capacity is greater than or equal to `new_capacity`, it does nothing.
  Otherwise, it should allocate enough memory so that the vector can store `new_capacity` number of elements.
*/
void resize(vector* v, size_t new_capacity);

// 1p
/**
  Returns the element at a given index. If num_elems < ix, the behaviour is undefined.
*/
int get(const vector* v, size_t ix);

// 3p
/**
  Inserts a new element at the end of the vector.

  If the vector doesn't have enough capacity, it allocates more memory, copies the existing elements,
  and then inserts the new element. If the vector has capacity = 0, the new capacity will be 1, otherwise the new
  capacity should be twice as big as the original one.
*/
void push_back(vector* v, int x);

// 3p
/**
  Inserts a new element at the front of the vector.

  If the vector doesn't have enough capacity, it allocates more memory, copies the existing elements,
  and then inserts the new element. If the vector has capacity = 0, the new capacity will be 2, otherwise the new
  capacity should be twice as big as the original one.
*/
void push_front(vector* v, int x);

// 5p
/**
  Inserts a new element at the the given index of the vector.

  If the vector doesn't have enough capacity, it allocates more memory, copies the existing elements,
  and then inserts the new element. If the vector has capacity = 0, the new capacity will be 2, otherwise the new
  capacity should be the double of the original one.
*/
void insert_at(vector* v, size_t ix, int elem);

// 2p
/**
  Removes the element at a given index from the vector. The capacity should not change.
*/
void remove_at(vector* v, size_t ix);

// 2p
/**
  Returns an iterator pointing to the first element of the vector.
*/
vector_iterator begin(const vector* v);

// 2p
/**
  Advances the iterator by one element forward. The behaviour is undefined if the iterator is pointing past the vector.
*/
void next(vector_iterator* it);

// 2p
/**
  Checks whether the iterator is pointing past the vector. Returns true if and only if the iterator is pointing to
  an element inside the vector, false otherwise.
*/
bool finished(vector_iterator it);

// 1p
/**
  Returns the element pointed by the iterator. If the iterator points past the vector, the behaviour is undefined.
*/
int get_elem(vector_iterator it);

// 3p
/**
  Sums up the elements starting from where the iterator is pointing to, until the end of the vector.
  The iterator will point past the vector after the call.
*/
long sum(vector_iterator it);

// 3p
// +2p: use iterators instead of directly accessing lhs->elems and rhs->elems 
/**
  Compares two vectors for equality. Returns true if and only if the vectors contain the exact same elements
  in the same order, false otherwise.
*/
bool equals(const vector* lhs, const vector* rhs);

#endif // VECTOR_H_
