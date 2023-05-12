#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int day1PartA(char filename[]) {
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

int day1PartB(char filename[]) {
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

int main() {
  int partA_example = day1PartA("example.txt");
  printf("Day 1 Part A (example):\t%d\n", partA_example);
  assert(partA_example == 514579);

  int partA_input = day1PartA("input.txt");
  printf("Day 1 Part A (input):\t%d\n", partA_input);
  assert(partA_input == 703131);

  int partB_example = day1PartB("example.txt");
  printf("Day 1 Part B (example):\t%d\n", partB_example);
  assert(partB_example == 241861950);

  int partB_input = day1PartB("input.txt");
  printf("Day 1 Part B (input):\t%d\n", partB_input);
  assert(partB_input == 272423970);

  return 0;
}
