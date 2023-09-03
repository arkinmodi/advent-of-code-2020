#include "day_03.h"

#include <assert.h>
#include <stdio.h>

#include "../common/CharList.h"

int test_part_a(char* filename, int expected) {
  CharList list;
  CharList_init_array(&list, 1000);

  if (parse_input(&list, filename)) {
    return 1;
  }

  int actual = day_3_part_a(&list);
  printf("Day 03 Part A (%s):\t%d\n", filename, actual);
  assert(actual == expected);

  CharList_free_array(&list);
  return 0;
}

int test_part_b(char* filename, unsigned int expected) {
  CharList list;
  CharList_init_array(&list, 1000);

  if (parse_input(&list, filename)) {
    return 1;
  }

  unsigned int actual = day_3_part_b(&list);
  printf("Day 03 Part B (%s):\t%u\n", filename, actual);
  assert(actual == expected);

  CharList_free_array(&list);
  return 0;
}

int test(void) {
  printf(
      "\n//////////////////////////////"
      " START DAY 03 TEST "
      "///////////////////////////////\n\n");

  test_part_a("example.txt", 7);
  test_part_a("input.txt", 184);

  test_part_b("example.txt", 336);
  test_part_b("input.txt", (unsigned)2431272960);

  printf(
      "\n///////////////////////////////"
      " END DAY 03 TEST "
      "////////////////////////////////\n\n");

  return 0;
}
