#include "day_01.h"

#include <assert.h>
#include <stdio.h>

int test_part_a(char* filename, int expected) {
  IntList list;
  IntList_init_array(&list, 200);

  if (parse_input(&list, filename)) {
    return 1;
  }

  int actual = day_1_part_a(&list);
  printf("Day 1 Part A (%s):\t%d\n", filename, actual);
  assert(actual == expected);

  IntList_free_array(&list);
  return 0;
}

int test_part_b(char* filename, int expected) {
  IntList list;
  IntList_init_array(&list, 200);

  if (parse_input(&list, filename)) {
    return 1;
  }

  int actual = day_1_part_b(&list);
  printf("Day 1 Part B (%s):\t%d\n", filename, actual);
  assert(actual == expected);

  IntList_free_array(&list);
  return 0;
}

int test(void) {
  printf(
      "\n//////////////////////////////"
      " START DAY 01 TEST "
      "///////////////////////////////\n\n");

  test_part_a("example.txt", 514579);
  test_part_a("input.txt", 703131);

  test_part_b("example.txt", 241861950);
  test_part_b("input.txt", 272423970);

  printf(
      "\n///////////////////////////////"
      " END DAY 01 TEST "
      "////////////////////////////////\n");

  return 0;
}
