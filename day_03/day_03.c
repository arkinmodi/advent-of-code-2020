#include "day_03.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/CharList.h"

int day_3_part_a(CharList* input_list) {
  // [x, y]
  int currPos[] = {0, 0};
  int trees = 0;
  int forrestWidth = strlen(input_list->arr[0]);

  while (currPos[1] < input_list->size - 1) {
    currPos[0] += 3;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input_list->arr[currPos[1]][currPos[0]] == '#') {
      trees++;
    }
  }
  return trees;
}

unsigned int day_3_part_b(CharList* input_list) {
  // [x, y]
  int currPos[2] = {0, 0};
  int trees[5] = {0, 0, 0, 0, 0};
  int forrestWidth = strlen(input_list->arr[0]);

  // Slope: right 1, down 1
  while (currPos[1] < input_list->size - 1) {
    currPos[0] += 1;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input_list->arr[currPos[1]][currPos[0]] == '#') {
      trees[0]++;
    }
  }

  currPos[0] = 0;
  currPos[1] = 0;

  // Slope: right 3, down 1
  while (currPos[1] < input_list->size - 1) {
    currPos[0] += 3;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input_list->arr[currPos[1]][currPos[0]] == '#') {
      trees[1]++;
    }
  }

  currPos[0] = 0;
  currPos[1] = 0;

  // Slope: right 5, down 1
  while (currPos[1] < input_list->size - 1) {
    currPos[0] += 5;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input_list->arr[currPos[1]][currPos[0]] == '#') {
      trees[2]++;
    }
  }

  currPos[0] = 0;
  currPos[1] = 0;

  // Slope: right 7, down 1
  while (currPos[1] < input_list->size - 1) {
    currPos[0] += 7;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input_list->arr[currPos[1]][currPos[0]] == '#') {
      trees[3]++;
    }
  }

  currPos[0] = 0;
  currPos[1] = 0;

  // Slope: right 1, down 2
  while (currPos[1] < input_list->size - 2) {
    currPos[0] += 1;
    currPos[1] += 2;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input_list->arr[currPos[1]][currPos[0]] == '#') {
      trees[4]++;
    }
  }
  return trees[0] * trees[1] * trees[2] * trees[3] * trees[4];
}

int parse_input(CharList* list, char* filename) {
  FILE* input_file;
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

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Missing input file!\n");
    return 1;
  }

  char* filename = argv[1];
  CharList input_list;
  CharList_init_array(&input_list, 323);

  if (parse_input(&input_list, filename)) {
    return 1;
  }

  int part_a = day_3_part_a(&input_list);
  printf("Day 03 Part A:\t%d\n", part_a);

  unsigned int part_b = day_3_part_b(&input_list);
  printf("Day 03 Part B:\t%u\n", part_b);

  CharList_free_array(&input_list);
  return 0;
}
