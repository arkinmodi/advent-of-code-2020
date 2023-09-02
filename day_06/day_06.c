#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int day6PartA(char filename[]) {
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

  bool groupAnswers[26];
  for (i = 0; i < sizeof(groupAnswers) / sizeof(groupAnswers[0]); i++) {
    groupAnswers[i] = false;
  }

  int output = 0;
  for (i = 0; i < size; i++) {
    while (i < size && strcmp(input[i], "")) {
      for (int j = 0; j < strlen(input[i]); j++) {
        groupAnswers[input[i][j] - 'a'] = true;
      }
      i++;
    }

    for (int j = 0; j < sizeof(groupAnswers) / sizeof(groupAnswers[0]); j++) {
      output += groupAnswers[j];
      groupAnswers[j] = false;
    }
  }

  return output;
}

int day6PartB(char filename[]) {
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

  int groupAnswers[26];
  for (i = 0; i < sizeof(groupAnswers) / sizeof(groupAnswers[0]); i++) {
    groupAnswers[i] = 0;
  }

  int output = 0;
  for (i = 0; i < size; i++) {
    int groupSize = 0;
    while (i < size && strcmp(input[i], "")) {
      for (int j = 0; j < strlen(input[i]); j++) {
        groupAnswers[input[i][j] - 'a']++;
      }
      groupSize++;
      i++;
    }

    for (int j = 0; j < sizeof(groupAnswers) / sizeof(groupAnswers[0]); j++) {
      if (groupAnswers[j] == groupSize) {
        output++;
      }
      groupAnswers[j] = 0;
    }
  }

  return output;
}

int main() {
  int partA_example = day6PartA("example.txt");
  printf("Day 6 Part A (example):\t%d\n", partA_example);
  assert(partA_example == 11);

  int partA_input = day6PartA("input.txt");
  printf("Day 6 Part A (input):\t%d\n", partA_input);
  assert(partA_input == 6532);

  int partB_example = day6PartB("example.txt");
  printf("Day 6 Part B (example):\t%d\n", partB_example);
  assert(partB_example == 6);

  int partB_input = day6PartB("input.txt");
  printf("Day 6 Part B (input):\t%d\n", partB_input);
  assert(partB_input == 3427);

  return 0;
}
