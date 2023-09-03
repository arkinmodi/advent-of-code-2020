#pragma once

#ifndef _COMMON_INT_LIST_H_
#define _COMMON_INT_LIST_H_

typedef struct {
  int capacity;
  int size;
  int *arr;
} IntList;

int IntList_at(IntList *list, int index);
int IntList_back(IntList *list);
int IntList_front(IntList *list);
int IntList_capacity(IntList *list);
int IntList_size(IntList *list);
void IntList_free_array(IntList *list);
void IntList_init_array(IntList *list, int capacity);
void IntList_insert(IntList *list, int index, int value);
void IntList_pop_back(IntList *list);
void IntList_print_list(IntList *list);
void IntList_push_back(IntList *list, int value);
void IntList_resize(IntList *list, int new_capacity);
void IntList_reverse(IntList *list);

#endif
