#include "CharList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CharList_init_array(CharList *list, int capacity) {
  list->arr = calloc(capacity, sizeof(char *));
  list->capacity = capacity;
  list->size = 0;
}

void CharList_free_array(CharList *list) {
  for (int i = 0; i < list->size; i++) {
    free(list->arr[i]);
  }
  free(list->arr);
  list->arr = NULL;
  list->capacity = list->size = 0;
}

int CharList_size(CharList *list) { return list->size; }

int CharList_capacity(CharList *list) { return list->capacity; }

char *CharList_at(CharList *list, int index) {
  if (index < 0) {
    index += list->size;
  }
  return list->arr[index];
}

char *CharList_front(CharList *list) { return list->arr[0]; }

char *CharList_back(CharList *list) { return list->arr[list->size - 1]; }

void CharList_insert(CharList *list, int index, char *value) {
  strcpy(list->arr[index], value);
}

void CharList_resize(CharList *list, int new_capacity) {
  char **new_arr = calloc(new_capacity, sizeof(char *));
  for (int i = 0; i < list->size; i++) {
    new_arr[i] = list->arr[i];
  }

  list->capacity = new_capacity;
  free(list->arr);
  list->arr = new_arr;
}

void CharList_reverse(CharList *list) {
  int i = 0;
  int j = list->size - 1;
  while (i < j) {
    char *temp = list->arr[j];
    list->arr[j] = list->arr[i];
    list->arr[i] = temp;
    i++;
    j--;
  }
}

void CharList_push_back(CharList *list, const char *value) {
  if (list->size == list->capacity) {
    CharList_resize(list, list->capacity * 2);
  }
  list->arr[list->size] = calloc(sizeof(char), strlen(value) + 1);
  strcpy(list->arr[list->size], value);
  list->size++;
}

void CharList_pop_back(CharList *list) { list->size--; }

void CharList_print_list(CharList *list) {
  printf("[");
  for (int i = 0; i < list->size - 1; i++) {
    printf("%s, ", list->arr[i]);
  }
  printf("%s]\n", list->arr[list->size - 1]);
}
