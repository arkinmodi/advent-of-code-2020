#include <stdio.h>

#include "../common/CharList.h"
#include "day_05.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Missing input file!\n");
    return 1;
  }

  char *filename = argv[1];
  CharList input_list;
  CharList_init_array(&input_list, 789);

  if (parse_input(&input_list, filename)) {
    return 1;
  }

  int part_a = day_5_part_a(&input_list);
  printf("Day 05 Part A:\t%d\n", part_a);

  int part_b = day_5_part_b(&input_list);
  printf("Day 05 Part B:\t%d\n", part_b);

  CharList_free_array(&input_list);
  return 0;
}
