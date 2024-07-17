#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vector.h"

// typedef struct {
//   size_t capacity; // maximum number of elements the vector can contain
//   size_t num_elems; // current number of elements in the vector
//   int* elems; // pointer to the underlying array
// } vector;

// typedef struct {
//   const vector* vec; // pointer to the underlying vector
//   size_t ix; // current index
// } vector_iterator;

void upscale_zero_element_vector(vector* v, int x);
void print_capacity_error(size_t cur_capacity,size_t cur_num_elems);
void insert_to_index_and_shift_vector(vector* v, int x, int index);

// memory alloc success has not been checked yet.
vector* mk_vector(int* p, size_t size)
{
  vector* pointer = malloc(sizeof(vector));
  pointer->capacity = size;
  pointer->num_elems = size;
  int* array = malloc(size * sizeof(int));
  memcpy(array, p, size * sizeof(int));
  pointer->elems = array;
  return pointer;
}

void free_vector(vector* v)
{
  free(v->elems);
  free(v);
  return;
}

void resize(vector* v, size_t new_capacity)
{
  size_t cur_capacity = v->capacity;
  if(cur_capacity >= new_capacity)
  {
    return;
  }
  int* new_array = malloc(sizeof(int) * new_capacity);
  int cur_size_occupied = v->num_elems * sizeof(int);
  int* cur_array = v->elems;
  memcpy(new_array, cur_array, cur_size_occupied);
  v->elems = new_array;
  free(cur_array);
  v->capacity = new_capacity;
  return;
}

int get(vector* v, size_t ix)
{
  int target = v->elems[ix];
  return target;
}

void push_back(vector* v, int x)
{
  size_t cur_capacity = v->capacity;
  size_t cur_num_elems = v->num_elems;
  if(cur_num_elems < cur_capacity)
  {
    v->elems[cur_num_elems] = x;
    v->num_elems++;
  }
  else if (cur_capacity > 0 && cur_num_elems == cur_capacity)
  {
    resize(v, cur_capacity * 2);
    v->elems[cur_num_elems] = x;
    v->num_elems++;
  }
  else if (cur_capacity == 0 && cur_num_elems == 0)
  {
    upscale_zero_element_vector(v, x);
  }
  else
  {
    print_capacity_error(cur_capacity, cur_num_elems);
  }
  return;
}

void push_front(vector* v, int x)
{
  size_t cur_capacity = v->capacity;
  size_t cur_num_elems = v->num_elems;
  if(cur_num_elems < cur_capacity)
  {
    insert_to_index_and_shift_vector(v, x, 0);
  }
  else if (cur_capacity > 0 && cur_num_elems == cur_capacity)
  {
      resize(v, cur_capacity * 2);
      insert_to_index_and_shift_vector(v, x, 0);
  }
  else if (cur_capacity == 0 && cur_num_elems == 0)
  {
    upscale_zero_element_vector(v, x);
  }
  else
  {
    print_capacity_error(cur_capacity, cur_num_elems);
  }
  return;
}

void upscale_zero_element_vector(vector* v, int x)
{
  int* array = malloc(sizeof(int));
    array[0] = x;  
    v->capacity = 1;
    v->num_elems = 1;
    free(v->elems);
    v->elems = array;
    return;
}

void print_capacity_error(size_t cur_capacity, size_t cur_num_elems)
{
  printf("Sth went wrong the cur_capacity is %li, and the cur_num_elems is %li, the function terminates.\n", cur_capacity, cur_num_elems);
}

//over indexing defense has not been implemented
void insert_at(vector* v, size_t ix, int elem)
{
  size_t cur_num_elems = v->num_elems;
  size_t cur_capacity = v->capacity;
  if (ix == 0)
  {
    push_front(v, elem);
  }
  else if (ix == cur_num_elems)
  {
    push_back(v, elem);
  }
  else if (cur_num_elems < cur_capacity)
  {
    insert_to_index_and_shift_vector(v, elem, ix);
  }
  else if (cur_num_elems == cur_capacity)
  {
    resize(v, cur_capacity * 2);
    insert_to_index_and_shift_vector(v, elem, ix);
  }
  else
  {
    print_capacity_error(cur_capacity, cur_num_elems);
  }

}

void insert_to_index_and_shift_vector(vector* v, int x, int index)
{
  size_t cur_num_elems = v->num_elems;
  size_t elems_after_index = cur_num_elems - index;
    memmove(&v->elems[index + 1], &v->elems[index], elems_after_index * sizeof(int));
    v->elems[index] = x;
    v->num_elems++;
}

// // 2p
// /**
//   Removes the element at a given index from the vector. The capacity should not change.
// */
// void remove_at(vector* v, size_t ix);

// // 2p
// /**
//   Returns an iterator pointing to the first element of the vector.
// */
// vector_iterator begin(const vector* v);

// // 2p
// /**
//   Advances the iterator by one element forward. The behaviour is undefined if the iterator is pointing past the vector.
// */
// void next(vector_iterator* it);

// // 2p
// /**
//   Checks whether the iterator is pointing past the vector. Returns true if and only if the iterator is pointing to
//   an element inside the vector, false otherwise.
// */
// bool finished(vector_iterator it);

// // 1p
// /**
//   Returns the element pointed by the iterator. If the iterator points past the vector, the behaviour is undefined.
// */
// int get_elem(vector_iterator it);

// // 3p
// /**
//   Sums up the elements starting from where the iterator is pointing to, until the end of the vector.
//   The iterator will point past the vector after the call.
// */
// long sum(vector_iterator* it);

// // 3p
// // +2p: use iterators instead of directly accessing lhs->elems and rhs->elems 
// /**
//   Compares two vectors for equality. Returns true if and only if the vectors contain the exact same elements
//   in the same order, false otherwise.
// */
// bool equals(const vector* lhs, const vector* rhs);

