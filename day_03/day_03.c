#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int day3PartA(char filename[]) {
  FILE *inputFile;
  inputFile = fopen(filename, "r");
  if (inputFile == NULL) {
    perror("Failed to open file");
    return -1;
  }

  char buffer[50];
  int size = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile)) {
    size++;
  }
  rewind(inputFile);

  char input[size][50];

  int i = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile) && i < size) {
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(input[i++], buffer);
  }

  if (fclose(inputFile)) {
    perror("Failed to close file");
    return -1;
  }

  // [x, y]
  int currPos[] = {0, 0};
  int trees = 0;
  int forrestWidth = strlen(input[0]);

  while (currPos[1] <= size) {
    currPos[0] += 3;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input[currPos[1]][currPos[0]] == '#') {
      trees++;
    }
  }

  return trees;
}

unsigned int day3PartB(char filename[]) {
  FILE *inputFile;
  inputFile = fopen(filename, "r");
  if (inputFile == NULL) {
    perror("Failed to open file");
    return -1;
  }

  char buffer[50];
  int size = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile)) {
    size++;
  }
  rewind(inputFile);

  char input[size][50];

  int i = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile) && i < size) {
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(input[i++], buffer);
  }

  if (fclose(inputFile)) {
    perror("Failed to close file");
    return -1;
  }

  // [x, y]
  int currPos[2] = {0, 0};
  int trees[5] = {0, 0, 0, 0, 0};
  int forrestWidth = strlen(input[0]);

  // Slope: right 1, down 1
  while (currPos[1] <= size) {
    currPos[0] += 1;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input[currPos[1]][currPos[0]] == '#') {
      trees[0]++;
    }
  }

  currPos[0] = 0;
  currPos[1] = 0;

  // Slope: right 3, down 1
  while (currPos[1] <= size) {
    currPos[0] += 3;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input[currPos[1]][currPos[0]] == '#') {
      trees[1]++;
    }
  }

  currPos[0] = 0;
  currPos[1] = 0;

  // Slope: right 5, down 1
  while (currPos[1] <= size) {
    currPos[0] += 5;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input[currPos[1]][currPos[0]] == '#') {
      trees[2]++;
    }
  }

  currPos[0] = 0;
  currPos[1] = 0;

  // Slope: right 7, down 1
  while (currPos[1] <= size) {
    currPos[0] += 7;
    currPos[1] += 1;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input[currPos[1]][currPos[0]] == '#') {
      trees[3]++;
    }
  }

  currPos[0] = 0;
  currPos[1] = 0;

  // Slope: right 1, down 2
  while (currPos[1] <= size) {
    currPos[0] += 1;
    currPos[1] += 2;

    if (currPos[0] >= forrestWidth) {
      currPos[0] = currPos[0] % forrestWidth;
    }

    if (input[currPos[1]][currPos[0]] == '#') {
      trees[4]++;
    }
  }
  return trees[0] * trees[1] * trees[2] * trees[3] * trees[4];
}

int main() {
  int partA_example = day3PartA("example.txt");
  printf("Day 3 Part A (example):\t%d\n", partA_example);
  assert(partA_example == 7);

  int partA_input = day3PartA("input.txt");
  printf("Day 3 Part A (input):\t%d\n", partA_input);
  assert(partA_input == 184);

  int partB_example = day3PartB("example.txt");
  printf("Day 3 Part B (example):\t%d\n", partB_example);
  assert(partB_example == 336);

  int partB_input = day3PartB("input.txt");
  printf("Day 3 Part B (input):\t%u\n", partB_input);
  assert(partB_input == (unsigned)2431272960);

  return 0;
}
