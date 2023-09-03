#pragma once

#ifndef _COMMON_CHAR_LIST_H_
#define _COMMON_CHAR_LIST_H_

typedef struct {
  char **arr;
  int capacity;
  int size;
} CharList;

char *CharList_at(CharList *list, int index);
char *CharList_back(CharList *list);
char *CharList_front(CharList *list);
int CharList_capacity(CharList *list);
int CharList_size(CharList *list);
void CharList_free_array(CharList *list);
void CharList_init_array(CharList *list, int capacity);
void CharList_insert(CharList *list, int index, char *value);
void CharList_pop_back(CharList *list);
void CharList_print_list(CharList *list);
void CharList_push_back(CharList *list, const char *value);
void CharList_resize(CharList *list, int new_capacity);
void CharList_reverse(CharList *list);

#endif
