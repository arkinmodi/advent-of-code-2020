#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Passport {
  bool byr;
  bool iyr;
  bool eyr;
  bool hgt;
  bool hcl;
  bool ecl;
  bool pid;
  bool cid;
};

int day4PartA(char filename[]) {
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

  int validPassports = 0;

  static const struct Passport emptyPassport;
  i = 0;
  while (i < size) {
    struct Passport passport = emptyPassport;

    while (i < size && strcmp(input[i], "") != 0) {
      char *split = strtok(input[i], " :");
      while (split != NULL) {
        if (strcmp(split, "byr") == 0) {
          passport.byr = true;
        } else if (strcmp(split, "iyr") == 0) {
          passport.iyr = true;
        } else if (strcmp(split, "eyr") == 0) {
          passport.eyr = true;
        } else if (strcmp(split, "hgt") == 0) {
          passport.hgt = true;
        } else if (strcmp(split, "hcl") == 0) {
          passport.hcl = true;
        } else if (strcmp(split, "ecl") == 0) {
          passport.ecl = true;
        } else if (strcmp(split, "pid") == 0) {
          passport.pid = true;
        } else if (strcmp(split, "cid") == 0) {
          passport.cid = true;
        }

        split = strtok(NULL, " :");
        split = strtok(NULL, " :");
      }
      i++;
    }

    if (passport.byr && passport.iyr && passport.eyr && passport.hgt &&
        passport.hcl && passport.ecl && passport.pid) {
      validPassports++;
    }

    i++;
  }

  return validPassports;
}

int day4PartB(char filename[]) {
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

  int validPassports = 0;

  static const struct Passport emptyPassport;
  i = 0;
  while (i < size) {
    struct Passport passport = emptyPassport;

    while (i < size && strcmp(input[i], "") != 0) {
      char *split = strtok(input[i], " :");
      while (split != NULL) {
        if (strcmp(split, "byr") == 0) {
          split = strtok(NULL, " :");
          int byr = atoi(split);
          passport.byr = strlen(split) == 4 && 1920 <= byr && byr <= 2002;

        } else if (strcmp(split, "iyr") == 0) {
          split = strtok(NULL, " :");
          int iyr = atoi(split);
          passport.iyr = strlen(split) == 4 && 2010 <= iyr && iyr <= 2020;

        } else if (strcmp(split, "eyr") == 0) {
          split = strtok(NULL, " :");
          int eyr = atoi(split);
          passport.eyr = strlen(split) == 4 && 2020 <= eyr && eyr <= 2030;

        } else if (strcmp(split, "hgt") == 0) {
          split = strtok(NULL, " :");

          int hgtLength = strlen(split);
          char hgtString[hgtLength - 2];
          char units[3];

          // strncpy(units, split + hgtLength - 2, 2);
          // strncpy(hgtString, split, hgtLength - 2);

          for (int j = 0; j < hgtLength - 2; j++) {
            hgtString[j] = split[j];
          }
          hgtString[hgtLength - 2] = '\0';

          units[0] = split[hgtLength - 2];
          units[1] = split[hgtLength - 1];
          units[2] = '\0';

          int hgt = atoi(hgtString);
          if (strcmp(units, "cm") == 0) {
            passport.hgt = 150 <= hgt && hgt <= 193;
          } else if (strcmp(units, "in") == 0) {
            passport.hgt = 59 <= hgt && hgt <= 76;
          }

        } else if (strcmp(split, "hcl") == 0) {
          split = strtok(NULL, " :");
          bool isValid = false;
          if (strlen(split) == 7 && split[0] == '#') {
            isValid = true;
            for (int j = 1; j < 7; j++) {
              if (!(('0' <= split[j] && split[j] <= '9') ||
                    ('a' <= split[j] && split[j] <= 'f'))) {
                isValid = false;
              }
            }
          }
          passport.hcl = isValid;

        } else if (strcmp(split, "ecl") == 0) {
          split = strtok(NULL, " :");
          passport.ecl =
              strcmp(split, "amb") == 0 || strcmp(split, "blu") == 0 ||
              strcmp(split, "brn") == 0 || strcmp(split, "gry") == 0 ||
              strcmp(split, "grn") == 0 || strcmp(split, "hzl") == 0 ||
              strcmp(split, "oth") == 0;

        } else if (strcmp(split, "pid") == 0) {
          split = strtok(NULL, " :");
          passport.pid = strlen(split) == 9;

        } else if (strcmp(split, "cid") == 0) {
          split = strtok(NULL, " :");
          passport.cid = true;
        }

        split = strtok(NULL, " :");
      }
      i++;
    }

    if (passport.byr && passport.iyr && passport.eyr && passport.hgt &&
        passport.hcl && passport.ecl && passport.pid) {
      validPassports++;
    }

    i++;
  }

  return validPassports;
}

int main() {
  int partA_example = day4PartA("example_partA.txt");
  printf("Day 4 Part A (example):\t%d\n", partA_example);
  assert(partA_example == 2);

  int partA_input = day4PartA("input.txt");
  printf("Day 4 Part A (input):\t%d\n", partA_input);
  assert(partA_input == 226);

  int partB_example = day4PartB("example_partB.txt");
  printf("Day 4 Part B (example):\t%d\n", partB_example);
  assert(partB_example == 4);

  int partB_input = day4PartB("input.txt");
  printf("Day 4 Part B (input):\t%u\n", partB_input);
  assert(partB_input == 160);

  return 0;
}
