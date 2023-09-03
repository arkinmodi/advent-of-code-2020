#include "day_06.h"

#include <assert.h>
#include <stdio.h>

#include "../common/CharList.h"

int test_part_a(char* filename, int expected) {
  CharList list;
  CharList_init_array(&list, 2148);

  if (parse_input(&list, filename)) {
    return 1;
  }

  int actual = day_6_part_a(&list);
  printf("Day 06 Part A (%s):\t%d\n", filename, actual);
  assert(actual == expected);

  CharList_free_array(&list);
  return 0;
}

int test_part_b(char* filename, int expected) {
  CharList list;
  CharList_init_array(&list, 2148);

  if (parse_input(&list, filename)) {
    return 1;
  }

  int actual = day_6_part_b(&list);
  printf("Day 06 Part B (%s):\t%d\n", filename, actual);
  assert(actual == expected);

  CharList_free_array(&list);
  return 0;
}

int main(void) {
  printf(
      "\n//////////////////////////////"
      " START DAY 06 TEST "
      "///////////////////////////////\n\n");

  test_part_a("example.txt", 11);
  test_part_a("input.txt", 6532);

  test_part_b("example.txt", 6);
  test_part_b("input.txt", 3427);

  printf(
      "\n///////////////////////////////"
      " END DAY 06 TEST "
      "////////////////////////////////\n\n");

  return 0;
}
