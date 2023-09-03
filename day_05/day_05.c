#include "day_05.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/CharList.h"

int calculate_seat_id(char *input) {
  unsigned long i = 0;

  int top = 127;
  int bottom = 0;
  while (i < 7) {
    if (input[i] == 'F') {
      top = top - ((top - bottom + 1) / 2);
    } else {
      bottom = bottom + ((top - bottom + 1) / 2);
    }
    i++;
  }

  int left = 0;
  int right = 7;
  while (i < strlen(input)) {
    if (input[i] == 'L') {
      right = right - ((right - left + 1) / 2);
    } else {
      left = left + ((right - left + 1) / 2);
    }
    i++;
  }
  return top * 8 + right;
}

int day_5_part_a(CharList *input_list) {
  int max_seat_id = 0;
  for (int i = 0; i < input_list->size; i++) {
    int seat_id = calculate_seat_id(input_list->arr[i]);
    if (seat_id > max_seat_id) {
      max_seat_id = seat_id;
    }
  }
  return max_seat_id;
}

int comparator(const void *p1, const void *p2) {
  return (*(int *)p1 - *(int *)p2);
}

int day_5_part_b(CharList *input_list) {
  int seat_ids[input_list->size];
  for (int i = 0; i < input_list->size; i++) {
    seat_ids[i] = calculate_seat_id(input_list->arr[i]);
  }

  qsort(seat_ids, input_list->size, sizeof(int), comparator);

  for (int i = 0; i < input_list->size - 1; i++) {
    if (seat_ids[i + 1] - seat_ids[i] > 1) {
      return seat_ids[i] + 1;
    }
  }
  return -1;
}

int parse_input(CharList *list, char *filename) {
  FILE *input_file;
  input_file = fopen(filename, "r");
  if (input_file == NULL) {
    fprintf(stderr, "Failed to open file: %s", filename);
    return 1;
  }

  char buffer[101];
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
