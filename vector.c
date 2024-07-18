#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vector.h"

void print_capacity_error(size_t cur_capacity,size_t cur_num_elems);
void insert_to_index_and_shift_vector(vector* v, int x, int index);
void delete_from_index_and_shift_vector(vector* v, int index);
void print_indexing_error(size_t cur_capacity, size_t cur_num_elems, size_t ix);
void print_overindexing_error(void);

vector* mk_vector(int* p, size_t size)
{
  vector* pointer = malloc(sizeof(vector));
  if(pointer == NULL)
  {
    printf("Pointer memory allocation failed, the program terminates.\n");
    return NULL;
  }
  pointer->capacity = size;
  pointer->num_elems = size;
  int* array = malloc(size * sizeof(int));
  if(array == NULL)
  {
    printf("Vector memory allocation failed, the program terminates.\n");
    return NULL;
  }
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
    if(new_array == NULL)
  {
    printf("Vector memory allocation failed, the program terminates.\n");
    return;
  }
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
  size_t cur_num_elems = v->num_elems;
  size_t cur_capacity = v->capacity;
  if(ix < cur_num_elems)
  {
    return v->elems[ix];
  }
  else 
  {
    print_indexing_error(cur_capacity, cur_num_elems, ix);
    return -1;
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

void delete_from_index_and_shift_vector(vector* v, int index)
{
  size_t cur_num_elems = v->num_elems;
  size_t elems_after_index = cur_num_elems - index;
    memmove(&v->elems[index], &v->elems[index + 1], elems_after_index * sizeof(int));
    v->num_elems--;
}

void print_capacity_error(size_t cur_capacity, size_t cur_num_elems)
{
  printf("Sth went wrong the cur_capacity is %li, and the cur_num_elems is %li, the function terminates.\n", cur_capacity, cur_num_elems);
}

void print_indexing_error(size_t cur_capacity, size_t cur_num_elems, size_t ix)
{
  printf("Sth went wrong the cur_capacity is %li, and the cur_num_elems is %li, and the requested index is %li the function terminates.\n",
     cur_capacity, cur_num_elems, ix);
}

void push_back(vector* v, int x)
{
  size_t cur_capacity = v->capacity;
  size_t cur_num_elems = v->num_elems;
  if(cur_capacity > 0 && cur_num_elems == cur_capacity)
  {
    resize(v, cur_capacity * 2);
  }
  else if (cur_capacity == 0 && cur_num_elems == 0)
  {
    resize(v, 1);
  }
  else if(cur_num_elems > cur_capacity)
  {
    print_capacity_error(cur_capacity, cur_num_elems);
    return;
  }
  insert_to_index_and_shift_vector(v, x, cur_num_elems);
  return;
}

void push_front(vector* v, int x)
{
  size_t cur_capacity = v->capacity;
  size_t cur_num_elems = v->num_elems;
  if (cur_capacity > 0 && cur_num_elems == cur_capacity)
  {
    resize(v, cur_capacity * 2);
  }
  else if (cur_capacity == 0 && cur_num_elems == 0)
  {
    resize(v, 1);
  }
  else if (cur_num_elems > cur_capacity)
  {
    print_capacity_error(cur_capacity, cur_num_elems);
    return;
  }
  insert_to_index_and_shift_vector(v, x, 0);
  return;
}

void insert_at(vector* v, size_t ix, int elem)
{
  size_t cur_num_elems = v->num_elems;
  size_t cur_capacity = v->capacity;
  if (cur_num_elems == cur_capacity)
  {
    resize(v, cur_capacity * 2);
  }
  else if (cur_capacity == 0 && cur_num_elems == 0)
  {
    resize(v, 1);
  }
  else if (cur_num_elems > cur_capacity || cur_num_elems < ix)
  {
    print_indexing_error(cur_capacity, cur_num_elems, ix);
     return;
  }
  insert_to_index_and_shift_vector(v, elem, ix);
  return;
}


void remove_at(vector* v, size_t ix)
{
  size_t cur_num_elems = v->num_elems;
  size_t cur_capacity = v->capacity;
  if(cur_num_elems <= cur_capacity && ix <= cur_num_elems)
  {
    delete_from_index_and_shift_vector(v, ix);
  }
  else 
  {
    print_indexing_error(cur_capacity, cur_num_elems, ix);
  }
  return;
}

vector_iterator begin(const vector* v)
{
  vector_iterator* iterator = malloc(sizeof(vector_iterator));
  // if(iterator == NULL)
  // {
  //   printf("Memory allocation failed, the program terminates.\n")
  //   return ???;
  // }
  iterator->vec = v;
  iterator->ix = 0;
  return *iterator;
}

void print_overindexing_error(void)
{
  printf("Indexing beyond the last element. The function terminates.\n");
}

void next(vector_iterator* it)
{
  if(!finished(*it))
  {
    it->ix++;
    return;
  }
  else{
    print_overindexing_error();
    return;
  }
}

bool finished(vector_iterator it)
{
  size_t cur_num_elems = it.vec->num_elems;
  size_t cur_ix = it.ix;
  return cur_ix >= cur_num_elems;
}

int get_elem(vector_iterator it)
{
  if(!finished(it))
  {
    return it.vec->elems[it.ix];
  }
  else
  {
    print_overindexing_error();
    return -1;
  }
}

long sum(vector_iterator* it)
{
  long res = 0;
  while (!finished(*it))
  {
    res+= get_elem(*it);
    it->ix++;
  }
  return res;
}

bool equals(const vector* lhs, const vector* rhs)
{
  if (lhs->num_elems == rhs->num_elems)
  {
    vector_iterator lsh_iterator = begin(lhs);
    vector_iterator rsh_iterator = begin(rhs);
    bool can_equal = get_elem(lsh_iterator) == get_elem(rsh_iterator);
    while(!finished(lsh_iterator) && can_equal)
    {
      can_equal = get_elem(lsh_iterator) == get_elem(rsh_iterator);
      next(&lsh_iterator);
      next(&rsh_iterator);
    }
    return can_equal;
  }
  else
  {
    return false;
  }
}

