#include "day_01.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  char buffer[6];
  while (fgets(buffer, sizeof(buffer) + 1, input_file)) {
    IntList_push_back(list, strtol(buffer, NULL, 10));
  }

  if (fclose(input_file)) {
    fprintf(stderr, "Failed to close file: %s", filename);
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Missing input file!\n");
    return 1;
  }

  char *filename = argv[1];
  IntList input_list;
  IntList_init_array(&input_list, 200);

  if (parse_input(&input_list, filename)) {
    return 1;
  }

  int part_a = day_1_part_a(&input_list);
  printf("Day 01 Part A:\t%d\n", part_a);

  int part_b = day_1_part_b(&input_list);
  printf("Day 01 Part B:\t%d\n", part_b);

  IntList_free_array(&input_list);

  return 0;
}
