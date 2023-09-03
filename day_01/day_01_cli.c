#include <stdio.h>

#include "../common/IntList.h"
#include "day_01.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Missing input file!\n");
    return 1;
  }

  char *filename = argv[1];
  IntList input_list;
  IntList_init_array(&input_list, 200);

  if (parse_input(&input_list, filename)) {
    return 1;
  }

  int part_a = day_1_part_a(&input_list);
  printf("Day 01 Part A:\t%d\n", part_a);

  int part_b = day_1_part_b(&input_list);
  printf("Day 01 Part B:\t%d\n", part_b);

  IntList_free_array(&input_list);

  return 0;
}
