#include "day_06.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/CharList.h"

int day_6_part_a(CharList *input_list) {
  bool group_answers[26];
  for (int i = 0; i < sizeof(group_answers) / sizeof(group_answers[0]); i++) {
    group_answers[i] = false;
  }

  int output = 0;
  for (int i = 0; i < input_list->size; i++) {
    while (i < input_list->size && strcmp(input_list->arr[i], "")) {
      for (int j = 0; j < strlen(input_list->arr[i]); j++) {
        group_answers[input_list->arr[i][j] - 'a'] = true;
      }
      i++;
    }

    for (int j = 0; j < sizeof(group_answers) / sizeof(group_answers[0]); j++) {
      output += group_answers[j];
      group_answers[j] = false;
    }
  }
  return output;
}

int day_6_part_b(CharList *input_list) {
  int group_answers[26];
  for (int i = 0; i < sizeof(group_answers) / sizeof(group_answers[0]); i++) {
    group_answers[i] = 0;
  }

  int output = 0;
  for (int i = 0; i < input_list->size; i++) {
    int group_size = 0;
    while (i < input_list->size && strcmp(input_list->arr[i], "")) {
      for (int j = 0; j < strlen(input_list->arr[i]); j++) {
        group_answers[input_list->arr[i][j] - 'a']++;
      }
      group_size++;
      i++;
    }

    for (int j = 0; j < sizeof(group_answers) / sizeof(group_answers[0]); j++) {
      if (group_answers[j] == group_size) {
        output++;
      }
      group_answers[j] = 0;
    }
  }
  return output;
}

int parse_input(CharList *list, char *filename) {
  FILE *input_file;
  input_file = fopen(filename, "r");
  if (input_file == NULL) {
    fprintf(stderr, "Failed to open file: %s", filename);
    return 1;
  }

  char buffer[100];
  while (fgets(buffer, sizeof(buffer) + 1, input_file)) {
    buffer[strcspn(buffer, "\n")] = 0;
    CharList_push_back(list, buffer);
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
  CharList input_list;
  CharList_init_array(&input_list, 2148);

  if (parse_input(&input_list, filename)) {
    return 1;
  }

  printf("%d\n", input_list.size);

  int part_a = day_6_part_a(&input_list);
  printf("Day 06 Part A:\t%d\n", part_a);

  int part_b = day_6_part_b(&input_list);
  printf("Day 06 Part B:\t%d\n", part_b);

  CharList_free_array(&input_list);
  return 0;
}
