#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateSeatId(char *input) {
  int i = 0;

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

int day5PartA(char filename[]) {
  FILE *inputFile;
  inputFile = fopen(filename, "r");
  if (inputFile == NULL) {
    perror("Failed to open file");
    return -1;
  }

  char buffer[100];
  int size = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile)) {
    size++;
  }
  rewind(inputFile);

  char input[size][100];

  int i = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile) && i < size) {
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(input[i++], buffer);
  }

  if (fclose(inputFile)) {
    perror("Failed to close file");
    return -1;
  }

  int maxSeatId = 0;
  for (i = 0; i < size; i++) {
    int seatId = calculateSeatId(input[i]);
    if (seatId > maxSeatId) {
      maxSeatId = seatId;
    }
  }
  return maxSeatId;
}

int comparator(const void *p1, const void *p2) {
  return (*(int *)p1 - *(int *)p2);
}

int day5PartB(char filename[]) {
  FILE *inputFile;
  inputFile = fopen(filename, "r");
  if (inputFile == NULL) {
    perror("Failed to open file");
    return -1;
  }

  char buffer[100];
  int size = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile)) {
    size++;
  }
  rewind(inputFile);

  char input[size][100];

  int i = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile) && i < size) {
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(input[i++], buffer);
  }

  if (fclose(inputFile)) {
    perror("Failed to close file");
    return -1;
  }

  int seatIds[size];
  for (i = 0; i < size; i++) {
    seatIds[i] = calculateSeatId(input[i]);
  }

  qsort(seatIds, size, sizeof(int), comparator);

  for (i = 0; i < size - 1; i++) {
    if (seatIds[i + 1] - seatIds[i] > 1) {
      return seatIds[i] + 1;
    }
  }

  return -1;
}

int main() {
  int partA_example = day5PartA("example.txt");
  printf("Day 5 Part A (example):\t%d\n", partA_example);
  assert(partA_example == 820);

  int partA_input = day5PartA("input.txt");
  printf("Day 5 Part A (input):\t%d\n", partA_input);
  assert(partA_input == 864);

  int partB_input = day5PartB("input.txt");
  printf("Day 5 Part B (input):\t%d\n", partB_input);
  assert(partB_input == 739);

  return 0;
}
