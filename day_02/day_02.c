#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/CharList.h"

int day_2_part_a(CharList *input_list) {
  int valid_passwords = 0;
  for (int i = 0; i < input_list->size; i++) {
    char copy[strlen(input_list->arr[i])];
    strcpy(copy, input_list->arr[i]);

    char *split = strtok(copy, "-");
    int min = atoi(split);

    split = strtok(NULL, " ");
    int max = atoi(split);

    char *letter = strtok(NULL, ":");
    char *password = strtok(NULL, " ");

    int count = 0;
    for (int j = 0; j < strlen(password); j++) {
      if (password[j] == letter[0]) {
        count++;
      }
    }

    if (min <= count && count <= max) {
      valid_passwords++;
    }
  }
  return valid_passwords;
}

int day_2_part_b(CharList *input_list) {
  int valid_passwords = 0;
  for (int i = 0; i < input_list->size; i++) {
    char copy[strlen(input_list->arr[i])];
    strcpy(copy, input_list->arr[i]);

    char *split = strtok(copy, "-");
    int position_a = atoi(split) - 1;

    split = strtok(NULL, " ");
    int position_b = atoi(split) - 1;

    char letter = strtok(NULL, ":")[0];
    char *password = strtok(NULL, " ");

    // if ((password[position_a] != password[position_b]) &&
    //     (password[position_a] == letter || password[position_b] == letter)) {
    //   valid_passwords++;
    // }

    if (password[position_a] == letter ^ password[position_b] == letter) {
      valid_passwords++;
    }
  }
  return valid_passwords;
}

int parse_input(CharList *list, char *filename) {
  FILE *input_file;
  input_file = fopen(filename, "r");
  if (input_file == NULL) {
    fprintf(stderr, "Failed to open file: %s", filename);
    return 1;
  }

  char buffer[50];
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
  CharList_init_array(&input_list, 1000);

  if (parse_input(&input_list, filename)) {
    return 1;
  }

  int part_a = day_2_part_a(&input_list);
  printf("Day 02 Part A:\t%d\n", part_a);

  int part_b = day_2_part_b(&input_list);
  printf("Day 02 Part B:\t%d\n", part_b);

  CharList_free_array(&input_list);
  return 0;
}
