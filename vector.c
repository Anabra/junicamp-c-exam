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

//Memory O N where N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, while when N gets big, 
//they get less significant.
//Runtime: O 1 (mallocs should be the slowest part)
vector* mk_vector(int* p, size_t size)
{
  vector* vector = malloc(sizeof(vector));
  if(vector == NULL)
  {
    printf("Pointer memory allocation failed, the program terminates.\n");
    return NULL;
  }
  vector->capacity = size;
  vector->num_elems = size;
  int* array = malloc(size * sizeof(int));
  if(array == NULL)
  {
    printf("Vector memory allocation failed, the program terminates.\n");
    return NULL;
  }
  memcpy(array, p, size * sizeof(int));
  vector->elems = array;
  return vector;
}

//Memory O1
//Runtime: freeing runtime unkown, probably O1
void free_vector(vector* v)
{
  free(v->elems);
  free(v);
  return;
}

//Memory ON where N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, 
//while when N gets big, they get less significant.
//Runtime: O N where N is the elem num (Note malloc time is unknown, with small elem num it could be the slowest part)
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

//Memory ON where N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, 
//while when N gets big, they get less significant.
//Runtime: O1
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

//Memory ON where N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, 
//while when N gets big, they get less significant.
//Runtime: ON where N is the element num that has to be shifted + inserted.
void insert_to_index_and_shift_vector(vector* v, int x, int index)
{
  size_t cur_num_elems = v->num_elems;
  size_t elem_num_after_index = cur_num_elems - index;
    memmove(&v->elems[index + 1], &v->elems[index], elem_num_after_index * sizeof(int));
    v->elems[index] = x;
    v->num_elems++;
}

//Memory ON where N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, 
//while when N gets big, they get less significant.
//Runtime: ON where N is the element num that has to be shifted + deleted.
void delete_from_index_and_shift_vector(vector* v, int index)
{
  size_t cur_num_elems = v->num_elems;
  size_t elem_num_after_index = cur_num_elems - index;
    memmove(&v->elems[index], &v->elems[index + 1], elem_num_after_index * sizeof(int));
    v->num_elems--;
}

//Memory O1
//Runtime: O1
void print_capacity_error(size_t cur_capacity, size_t cur_num_elems)
{
  printf("Sth went wrong the cur_capacity is %li, and the cur_num_elems is %li, the function terminates.\n", cur_capacity, cur_num_elems);
}

//Memory O1
//Runtime: O1
void print_indexing_error(size_t cur_capacity, size_t cur_num_elems, size_t ix)
{
  printf("Sth went wrong the cur_capacity is %li, and the cur_num_elems is %li, and the requested index is %li the function terminates.\n",
     cur_capacity, cur_num_elems, ix);
}

//Memory ON where N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, 
//while when N gets big, they get less significant.
//Runtime: ON where N is the element num (because of possible resize)
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

//Memory ON where N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, 
//while when N gets big, they get less significant.
//Runtime: ON where N is the element num.
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

//Memory ON where N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, 
//while when N gets big, they get less significant.
//Runtime: ON where N is the element num due to possible resize.
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

//Memory ON where N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, 
//while when N gets big, they get less significant.
//Runtime: ON where N is the element num that has to be shifted + deleted.
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

//Memory ON where N is the vector size.
//Runtime: O1 malloc is the slowest.
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

//Memory O1
//Runtime: O1
void print_overindexing_error(void)
{
  printf("Indexing beyond the last element. The function terminates.\n");
}

//Memory O1
//Runtime: O1
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

//Memory O1
//Runtime: O1
bool finished(vector_iterator it)
{
  size_t cur_num_elems = it.vec->num_elems;
  size_t cur_ix = it.ix;
  return cur_ix >= cur_num_elems;
}

//Memory O1
//Runtime: O1
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


//Memory ON N is the array size. Note, that if N is really small, the pointer sizes and longs will take the majority of space, 
//while when N gets big, they get less significant.
//Runtime: ON where N is the element num
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

//Memory ON N is the array size.
//Runtime: ON where N is the sum of the element nums
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

