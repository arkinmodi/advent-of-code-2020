#include "day_02.h"

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
    for (unsigned long j = 0; j < strlen(password); j++) {
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

    if ((password[position_a] != password[position_b]) &&
        (password[position_a] == letter || password[position_b] == letter)) {
      valid_passwords++;
    }

    // if (password[position_a] == letter ^ password[position_b] == letter)
    // {
    //   valid_passwords++;
    // }
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

  char buffer[51];
  while (fgets(buffer, sizeof(buffer), input_file)) {
    buffer[strcspn(buffer, "\n")] = 0;
    CharList_push_back(list, buffer);
  }

  if (fclose(input_file)) {
    fprintf(stderr, "Failed to close file: %s", filename);
    return 1;
  }
  return 0;
}
