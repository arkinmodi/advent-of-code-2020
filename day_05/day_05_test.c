#include "day_05.h"

#include <assert.h>
#include <stdio.h>

#include "../common/CharList.h"

int test_part_a(char* filename, int expected) {
  CharList list;
  CharList_init_array(&list, 789);

  if (parse_input(&list, filename)) {
    return 1;
  }

  int actual = day_5_part_a(&list);
  printf("Day 05 Part A (%s):\t%d\n", filename, actual);
  assert(actual == expected);

  CharList_free_array(&list);
  return 0;
}

int test_part_b(char* filename, int expected) {
  CharList list;
  CharList_init_array(&list, 789);

  if (parse_input(&list, filename)) {
    return 1;
  }

  int actual = day_5_part_b(&list);
  printf("Day 05 Part B (%s):\t%d\n", filename, actual);
  assert(actual == expected);

  CharList_free_array(&list);
  return 0;
}

int test(void) {
  printf(
      "\n//////////////////////////////"
      " START DAY 05 TEST "
      "///////////////////////////////\n\n");

  test_part_a("example.txt", 820);
  test_part_a("input.txt", 864);

  test_part_b("input.txt", 739);

  printf(
      "\n///////////////////////////////"
      " END DAY 05 TEST "
      "////////////////////////////////\n\n");

  return 0;
}
