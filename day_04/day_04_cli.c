#include <stdio.h>

#include "../common/CharList.h"
#include "day_04.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Missing input file!\n");
    return 1;
  }

  char* filename = argv[1];
  CharList input_list;
  CharList_init_array(&input_list, 1100);

  if (parse_input(&input_list, filename)) {
    return 1;
  }

  int part_a = day_4_part_a(&input_list);
  printf("Day 04 Part A:\t%d\n", part_a);

  int part_b = day_4_part_b(&input_list);
  printf("Day 04 Part B:\t%d\n", part_b);

  CharList_free_array(&input_list);
  return 0;
}
