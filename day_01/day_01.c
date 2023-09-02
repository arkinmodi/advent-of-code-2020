#include "day_01.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int day_1_part_a(char filename[]) {
  FILE *inputFile;
  inputFile = fopen(filename, "r");
  if (inputFile == NULL) {
    perror("Failed to open file");
    return 1;
  }

  char buffer[6];
  int numOfExpenses = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile)) {
    numOfExpenses++;
  }
  rewind(inputFile);

  int expenses[numOfExpenses];

  int i = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile) && i < numOfExpenses) {
    expenses[i++] = strtol(buffer, NULL, 10);
  }

  if (fclose(inputFile)) {
    perror("Failed to close file");
    return 1;
  }

  for (i = 0; i < numOfExpenses; i++) {
    for (int j = i + 1; j < numOfExpenses; j++) {
      if (expenses[i] + expenses[j] == 2020) {
        return expenses[i] * expenses[j];
      }
    }
  }
  return 0;
}

int day_1_part_b(char filename[]) {
  FILE *inputFile;
  inputFile = fopen(filename, "r");
  if (inputFile == NULL) {
    perror("Failed to open file");
    return 1;
  }

  char buffer[6];
  int numOfExpenses = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile)) {
    numOfExpenses++;
  }
  rewind(inputFile);

  int expenses[numOfExpenses];

  int i = 0;
  while (fgets(buffer, sizeof(buffer) + 1, inputFile) && i < numOfExpenses) {
    expenses[i++] = strtol(buffer, NULL, 10);
  }

  if (fclose(inputFile)) {
    perror("Failed to close file");
    return 1;
  }

  for (i = 0; i < numOfExpenses; i++) {
    for (int j = i + 1; j < numOfExpenses; j++) {
      for (int k = j + 1; k < numOfExpenses; k++) {
        if (expenses[i] + expenses[j] + expenses[k] == 2020) {
          return expenses[i] * expenses[j] * expenses[k];
        }
      }
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Missing input file!\n");
    return 1;
  }
  char *filename = argv[1];

  int part_a = day_1_part_a(filename);
  printf("Day 1 Part A:\t%d\n", part_a);

  int part_b = day_1_part_b(filename);
  printf("Day 1 Part B:\t%d\n", part_b);

  return 0;
}
