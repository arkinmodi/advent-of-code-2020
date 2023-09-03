#include "day_04.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/CharList.h"

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

int day_4_part_a(CharList* input_list) {
  int valid_passports = 0;

  static const struct Passport empty_passport;
  int i = 0;
  while (i < input_list->size) {
    struct Passport passport = empty_passport;

    while (i < input_list->size && strcmp(input_list->arr[i], "") != 0) {
      char* split = strtok(input_list->arr[i], " :");
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
      valid_passports++;
    }

    i++;
  }
  return valid_passports;
}

int day_4_part_b(CharList* input_list) {
  int valid_passports = 0;

  static const struct Passport empty_passport;
  int i = 0;
  while (i < input_list->size) {
    struct Passport passport = empty_passport;

    while (i < input_list->size && strcmp(input_list->arr[i], "") != 0) {
      char* split = strtok(input_list->arr[i], " :");
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

          int hgt_length = strlen(split);
          char hgt_string[hgt_length - 2];
          char units[3];

          // strncpy(units, split + hgt_length - 2, 2);
          // strncpy(hgt_string, split, hgt_length - 2);

          for (int j = 0; j < hgt_length - 2; j++) {
            hgt_string[j] = split[j];
          }
          hgt_string[hgt_length - 2] = '\0';

          units[0] = split[hgt_length - 2];
          units[1] = split[hgt_length - 1];
          units[2] = '\0';

          int hgt = atoi(hgt_string);
          if (strcmp(units, "cm") == 0) {
            passport.hgt = 150 <= hgt && hgt <= 193;
          } else if (strcmp(units, "in") == 0) {
            passport.hgt = 59 <= hgt && hgt <= 76;
          }

        } else if (strcmp(split, "hcl") == 0) {
          split = strtok(NULL, " :");
          bool is_valid = false;
          if (strlen(split) == 7 && split[0] == '#') {
            is_valid = true;
            for (int j = 1; j < 7; j++) {
              if (!(('0' <= split[j] && split[j] <= '9') ||
                    ('a' <= split[j] && split[j] <= 'f'))) {
                is_valid = false;
              }
            }
          }
          passport.hcl = is_valid;

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
      valid_passports++;
    }

    i++;
  }

  return valid_passports;
}

int parse_input(CharList* list, char* filename) {
  FILE* input_file;
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
