#include "IntList.h"

#include <stdio.h>
#include <stdlib.h>

void IntList_init_array(IntList *list, int capacity) {
  list->arr = calloc(capacity, sizeof(int));
  list->capacity = capacity;
  list->size = 0;
}

void IntList_free_array(IntList *list) {
  free(list->arr);
  list->arr = NULL;
  list->capacity = list->size = 0;
}

int IntList_size(IntList *list) { return list->size; }

int IntList_capacity(IntList *list) { return list->capacity; }

int IntList_at(IntList *list, int index) {
  if (index < 0) {
    index += list->size;
  }
  return list->arr[index];
}

int IntList_front(IntList *list) { return list->arr[0]; }

int IntList_back(IntList *list) { return list->arr[list->size - 1]; }

void IntList_insert(IntList *list, int index, int value) {
  list->arr[index] = value;
}

void IntList_resize(IntList *list, int new_capacity) {
  int *new_arr = calloc(new_capacity, sizeof(int));
  for (int i = 0; i < list->size; i++) {
    new_arr[i] = list->arr[i];
  }

  list->capacity = new_capacity;
  free(list->arr);
  list->arr = new_arr;
}

void IntList_reverse(IntList *list) {
  int i = 0;
  int j = list->size - 1;
  while (i < j) {
    int temp = list->arr[j];
    list->arr[j] = list->arr[i];
    list->arr[i] = temp;
    i++;
    j--;
  }
}

void IntList_push_back(IntList *list, int value) {
  if (list->size == list->capacity) {
    IntList_resize(list, list->capacity * 2);
  }
  list->arr[list->size] = value;
  list->size++;
}

void IntList_pop_back(IntList *list) { list->size--; }

void IntList_print_list(IntList *list) {
  printf("[");
  for (int i = 0; i < list->size - 1; i++) {
    printf("%d, ", list->arr[i]);
  }
  printf("%d]\n", list->arr[list->size - 1]);
}
