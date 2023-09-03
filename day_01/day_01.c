#include "day_01.h"

#include <stdio.h>
#include <stdlib.h>

#include "../common/IntList.h"

int day_1_part_a(IntList *input_list) {
  for (int i = 0; i < input_list->size; i++) {
    for (int j = i + 1; j < input_list->size; j++) {
      if (input_list->arr[i] + input_list->arr[j] == 2020) {
        return input_list->arr[i] * input_list->arr[j];
      }
    }
  }
  return 0;
}

int day_1_part_b(IntList *input_list) {
  for (int i = 0; i < input_list->size; i++) {
    for (int j = i + 1; j < input_list->size; j++) {
      for (int k = j + 1; k < input_list->size; k++) {
        if (input_list->arr[i] + input_list->arr[j] + input_list->arr[k] ==
            2020) {
          return input_list->arr[i] * input_list->arr[j] * input_list->arr[k];
        }
      }
    }
  }
  return 0;
}

int parse_input(IntList *list, char *filename) {
  FILE *input_file;
  input_file = fopen(filename, "r");
  if (input_file == NULL) {
    fprintf(stderr, "Failed to open file: %s", filename);
    return 1;
  }

  char buffer[7];
  while (fgets(buffer, sizeof(buffer), input_file)) {
    IntList_push_back(list, strtol(buffer, NULL, 10));
  }

  if (fclose(input_file)) {
    fprintf(stderr, "Failed to close file: %s", filename);
    return 1;
  }
  return 0;
}
