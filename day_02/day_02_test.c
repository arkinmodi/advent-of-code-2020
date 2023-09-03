#include "day_02.h"

#include <assert.h>
#include <stdio.h>

#include "../common/CharList.h"

int test_part_a(char* filename, int expected) {
  CharList list;
  CharList_init_array(&list, 1000);

  if (parse_input(&list, filename)) {
    return 1;
  }

  int actual = day_2_part_a(&list);
  printf("Day 02 Part A (%s):\t%d\n", filename, actual);
  assert(actual == expected);

  CharList_free_array(&list);
  return 0;
}

int test_part_b(char* filename, int expected) {
  CharList list;
  CharList_init_array(&list, 1000);

  if (parse_input(&list, filename)) {
    return 1;
  }

  int actual = day_2_part_b(&list);
  printf("Day 02 Part B (%s):\t%d\n", filename, actual);
  assert(actual == expected);

  CharList_free_array(&list);
  return 0;
}

int test(void) {
  printf(
      "\n//////////////////////////////"
      " START DAY 02 TEST "
      "///////////////////////////////\n\n");

  test_part_a("example.txt", 2);
  test_part_a("input.txt", 500);

  test_part_b("example.txt", 1);
  test_part_b("input.txt", 313);

  printf(
      "\n///////////////////////////////"
      " END DAY 02 TEST "
      "////////////////////////////////\n\n");

  return 0;
}
