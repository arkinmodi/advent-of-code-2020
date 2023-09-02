#include "day_01.h"

#include <assert.h>
#include <stdio.h>

int test(void) {
  printf(
      "\n//////////////////////////////"
      " START DAY 01 TEST "
      "///////////////////////////////\n\n");

  int partA_example = day_1_part_a("example.txt");
  printf("Day 1 Part A (example):\t%d\n", partA_example);
  assert(partA_example == 514579);

  int partA_input = day_1_part_a("input.txt");
  printf("Day 1 Part A (input):\t%d\n", partA_input);
  assert(partA_input == 703131);

  int partB_example = day_1_part_b("example.txt");
  printf("Day 1 Part B (example):\t%d\n", partB_example);
  assert(partB_example == 241861950);

  int partB_input = day_1_part_b("input.txt");
  printf("Day 1 Part B (input):\t%d\n", partB_input);
  assert(partB_input == 272423970);

  printf(
      "\n///////////////////////////////"
      " END DAY 01 TEST "
      "////////////////////////////////\n");

  return 0;
}
