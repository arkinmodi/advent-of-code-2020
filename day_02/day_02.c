#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int day2PartA(char filename[]) {
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

  int validPasswords = 0;
  for (int i = 0; i < size; i++) {
    char *split = strtok(input[i], "-");
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
      validPasswords++;
    }
  }

  return validPasswords;
}

int day2PartB(char filename[]) {
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

  int validPasswords = 0;
  for (int i = 0; i < size; i++) {
    char *split = strtok(input[i], "-");
    int positionA = atoi(split) - 1;

    split = strtok(NULL, " ");
    int positionB = atoi(split) - 1;

    char letter = strtok(NULL, ":")[0];
    char *password = strtok(NULL, " ");

    // if ((password[positionA] != password[positionB]) &&
    //     (password[positionA] == letter || password[positionB] == letter)) {
    //   validPasswords++;
    // }

    if (password[positionA] == letter ^ password[positionB] == letter) {
      validPasswords++;
    }
  }

  return validPasswords;
}

int main() {
  int partA_example = day2PartA("example.txt");
  printf("Day 2 Part A (example):\t%d\n", partA_example);
  assert(partA_example == 2);

  int partA_input = day2PartA("input.txt");
  printf("Day 2 Part A (input):\t%d\n", partA_input);
  assert(partA_input == 500);

  int partB_example = day2PartB("example.txt");
  printf("Day 2 Part B (example):\t%d\n", partB_example);
  assert(partB_example == 1);

  int partB_input = day2PartB("input.txt");
  printf("Day 2 Part B (input):\t%d\n", partB_input);
  assert(partB_input == 313);

  return 0;
}
