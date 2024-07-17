#include "vector.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void print_tests_passed(char* test_name) {
  printf("%s tests passed!\n", test_name);
}

void test_mk_vector() {
  int arr[] = {0, 5, 5, 3, 4};
  vector* v = mk_vector(arr, 5);

  assert(v->capacity == 5);
  assert(v->num_elems == 5);
  assert(v->elems[0] == 0);
  assert(v->elems[2] == 5);
  assert(v->elems[4] == 4);

  free(v->elems);
  print_tests_passed("mk_vector");
}

void test_free_vector() {
  int arr1[] = {0, 1, 2, 3};

  int* arr2 = malloc(4 * sizeof(int));
  arr2[0] = 0;
  arr2[1] = 1;
  arr2[2] = 2;
  arr2[3] = 3;

  vector* v1 = mk_vector(arr1, 4);
  vector* v2 = mk_vector(arr1, 4);
  vector* v3 = mk_vector(arr2, 4);
  vector* v4 = mk_vector(arr2, 4);

  free_vector(v1);
  for (int i = 0; i < 4; i++) {
    assert(arr1[i] == i);
    assert(v2->elems[i] == i);
  }

  free_vector(v2);
  for (int i = 0; i < 4; i++) {
    assert(arr1[i] == i);
  }

  free(arr2);
  free_vector(v3);
  for (int i = 0; i < 4; i++) {
    assert(v4->elems[i] == i);
  }

  free_vector(v4);

  print_tests_passed("free_vector");
}

void test_resize() {
  int arr[] = {0, 5, 5, 3, 4};
  vector* v = mk_vector(arr, 5);

  assert(v->capacity == 5);
  assert(v->num_elems == 5);

  resize(v, 3);
  assert(v->capacity == 5);
  assert(v->num_elems == 5);

  resize(v, 5);
  assert(v->capacity == 5);
  assert(v->num_elems == 5);

  resize(v, 7);
  assert(v->capacity == 7);
  assert(v->num_elems == 5);

  free_vector(v);
  print_tests_passed("resize");
}

void test_get() {
  int arr[] = {0, 1, 5, 3};
  vector* v = mk_vector(arr, 4);

  assert(get(v, 0) == 0);
  assert(get(v, 1) == 1);
  assert(get(v, 2) == 5);
  assert(get(v, 3) == 3);

  free_vector(v);
  print_tests_passed("get");
}

void test_push_back() {
  int arr[] = {};
  vector* v = mk_vector(arr, 0);

  assert(v->capacity == 0);
  assert(v->num_elems == 0);

  push_back(v, 0);
  assert(v->capacity == 1);
  assert(v->num_elems == 1);
  assert(v->elems[0] == 0);

  push_back(v, 1);
  assert(v->capacity == 2);
  assert(v->num_elems == 2);
  assert(v->elems[0] == 0);
  assert(v->elems[1] == 1);

  push_back(v, 2);
  assert(v->capacity == 4);
  assert(v->num_elems == 3);
  assert(v->elems[0] == 0);
  assert(v->elems[1] == 1);
  assert(v->elems[2] == 2);

  push_back(v, 3);
  assert(v->capacity == 4);
  assert(v->num_elems == 4);
  assert(v->elems[0] == 0);
  assert(v->elems[1] == 1);
  assert(v->elems[2] == 2);
  assert(v->elems[3] == 3);

  free_vector(v);
  print_tests_passed("push_back");
}

void test_push_front() {
  int arr[] = {};
  vector* v = mk_vector(arr, 0);

  assert(v->capacity == 0);
  assert(v->num_elems == 0);

  push_front(v, 0);
  assert(v->capacity == 1);
  assert(v->num_elems == 1);
  assert(v->elems[0] == 0);

  push_front(v, 1);
  assert(v->capacity == 2);
  assert(v->num_elems == 2);
  assert(v->elems[0] == 1);
  assert(v->elems[1] == 0);

  push_front(v, 2);
  assert(v->capacity == 4);
  assert(v->num_elems == 3);
  assert(v->elems[0] == 2);
  assert(v->elems[1] == 1);
  assert(v->elems[2] == 0);

  push_front(v, 3);
  assert(v->capacity == 4);
  assert(v->num_elems == 4);
  assert(v->elems[0] == 3);
  assert(v->elems[1] == 2);
  assert(v->elems[2] == 1);
  assert(v->elems[3] == 0);

  free_vector(v);
  print_tests_passed("push_front");
}

void test_insert_at() {
  int arr[] = {0, 1, 2};
  vector* v = mk_vector(arr, 3);

  assert(v->capacity == 3);
  assert(v->num_elems == 3);

  insert_at(v, 1, 5);
  assert(v->capacity == 6);
  assert(v->num_elems == 4);
  assert(v->elems[0] == 0);
  assert(v->elems[1] == 5);
  assert(v->elems[2] == 1);
  assert(v->elems[3] == 2);

  insert_at(v, 0, 5);
  assert(v->capacity == 6);
  assert(v->num_elems == 5);
  assert(v->elems[0] == 5);
  assert(v->elems[1] == 0);
  assert(v->elems[2] == 5);
  assert(v->elems[3] == 1);
  assert(v->elems[4] == 2);

  insert_at(v, 5, 5);
  assert(v->capacity == 6);
  assert(v->num_elems == 6);
  assert(v->elems[0] == 5);
  assert(v->elems[1] == 0);
  assert(v->elems[2] == 5);
  assert(v->elems[3] == 1);
  assert(v->elems[4] == 2);
  assert(v->elems[5] == 5);

  free_vector(v);
  print_tests_passed("insert_at");
}

// void test_remove_at() {
//   int arr[] = {0, 1, 2, 3};
//   vector* v = mk_vector(arr, 4);

//   assert(v->capacity == 4);
//   assert(v->num_elems == 4);

//   remove_at(v, 1);
//   assert(v->capacity == 4);
//   assert(v->num_elems == 3);
//   assert(v->elems[0] == 0);
//   assert(v->elems[1] == 2);
//   assert(v->elems[2] == 3);

//   remove_at(v, 3);
//   assert(v->capacity == 4);
//   assert(v->num_elems == 2);
//   assert(v->elems[0] == 0);
//   assert(v->elems[1] == 2);

//   remove_at(v, 0);
//   assert(v->capacity == 4);
//   assert(v->num_elems == 1);
//   assert(v->elems[0] == 2);

//   remove_at(v, 0);
//   assert(v->capacity == 4);
//   assert(v->num_elems == 0);

//   free_vector(v);
//   print_tests_passed("remove_at");
// }

// void test_begin() {
//   int arr[] = {0, 5, 5, 3, 4};
//   vector* v = mk_vector(arr, 5);

//   vector_iterator it = begin(v);
//   assert(it.ix == 0);
//   assert(it.vec == v);

//   free_vector(v);
//   print_tests_passed("begin");
// }

// void test_next() {
//   int arr[] = {0, 5, 5, 3, 4};
//   vector* v = mk_vector(arr, 5);

//   vector_iterator it = begin(v);
//   assert(it.ix == 0);
//   assert(it.vec == v);

//   next(&it);
//   assert(it.ix == 1);
//   assert(it.vec == v);

//   next(&it);
//   assert(it.ix == 2);
//   assert(it.vec == v);

//   free_vector(v);
//   print_tests_passed("next");
// }

// void test_finished() {
//   int arr[] = {0, 5, 5, 3, 4};
//   vector* v = mk_vector(arr, 5);

//   vector_iterator it = begin(v);
//   assert(it.ix == 0);
//   assert(it.vec == v);

//   next(&it);
//   assert(it.ix == 1);
//   assert(it.vec == v);
//   assert(!finished(it));

//   next(&it);
//   assert(it.ix == 2);
//   assert(it.vec == v);
//   assert(!finished(it));

//   next(&it);
//   next(&it);
//   assert(!finished(it));

//   next(&it);
//   assert(finished(it));

//   free_vector(v);
//   print_tests_passed("finished");
// }

// void test_get_elem() {
//   int arr[] = {0, 1, 2};
//   vector* v = mk_vector(arr, 3);

//   vector_iterator it = begin(v);
//   assert(get_elem(it) == 0);

//   next(&it);
//   assert(get_elem(it) == 1);

//   next(&it);
//   assert(get_elem(it) == 2);

//   free_vector(v);
//   print_tests_passed("get_elem");
// }


// void test_vector_iterator() {
//   int arr[] = {0, 5, 5, 3, 4};
//   vector* v = mk_vector(arr, 5);

//   int i = 0;
//   for (vector_iterator it = begin(v); !finished(it); next(&it)) {
//     assert(get_elem(it) == arr[i]);
//     i++;
//   }

//   free_vector(v);
//   print_tests_passed("vector iterator");
// }

// void test_sum() {
//   int arr[] = {0, 5, 5, 3, 4};
//   vector* v = mk_vector(arr, 5);

//   {
//     vector_iterator it = begin(v);
//     assert(sum(&it) == 17);
//   }

//   {
//     vector_iterator it = begin(v);
//     next(&it);
//     next(&it);
//     assert(sum(&it) == 12);
//   }

//   free_vector(v);
//   print_tests_passed("sum");
// }

// void test_equals() {
//   int arr1[] = {0, 1, 2, 3};
//   int arr2[] = {0, 1, 2, 3};
//   int arr3[] = {0, 1, 2};
//   int arr4[] = {0, 1, 2, 3, 4};
//   int arr5[] = {1, 1, 2, 3};
//   int arr6[] = {0, 1, 8, 3, 4};
//   int arr7[] = {0, 1, 2, 8};

//   vector* v1 = mk_vector(arr1, 4);
//   vector* v2 = mk_vector(arr2, 4);
//   vector* v3 = mk_vector(arr3, 3);
//   vector* v4 = mk_vector(arr4, 5);
//   vector* v5 = mk_vector(arr5, 4);
//   vector* v6 = mk_vector(arr6, 5);
//   vector* v7 = mk_vector(arr7, 4);

//   assert(equals(v1, v1));
//   assert(equals(v1, v2));
//   assert(equals(v2, v1));

//   assert(!equals(v1, v3));
//   assert(!equals(v1, v4));
//   assert(!equals(v1, v5));
//   assert(!equals(v1, v6));
//   assert(!equals(v1, v7));

//   assert(!equals(v3, v1));
//   assert(!equals(v4, v1));
//   assert(!equals(v5, v1));
//   assert(!equals(v6, v1));
//   assert(!equals(v7, v1));

//   free_vector(v1);
//   free_vector(v2);
//   free_vector(v3);
//   free_vector(v4);
//   free_vector(v5);
//   free_vector(v6);
//   free_vector(v7);
//   print_tests_passed("equals");
// }

int main(void) {
  test_mk_vector();
  test_free_vector();
  test_resize();

  test_get();
  test_push_back();
  test_push_front();
  test_insert_at();
  // test_remove_at();

  // test_begin();
  // test_next();
  // test_finished();
  // test_get_elem();
  // test_vector_iterator();
  // test_sum();
  // test_equals();

  // print_tests_passed("All");

  return 0;
}
