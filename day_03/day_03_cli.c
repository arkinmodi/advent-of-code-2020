#include <stdio.h>

#include "../common/CharList.h"
#include "day_03.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Missing input file!\n");
    return 1;
  }

  char* filename = argv[1];
  CharList input_list;
  CharList_init_array(&input_list, 323);

  if (parse_input(&input_list, filename)) {
    return 1;
  }

  int part_a = day_3_part_a(&input_list);
  printf("Day 03 Part A:\t%d\n", part_a);

  unsigned int part_b = day_3_part_b(&input_list);
  printf("Day 03 Part B:\t%u\n", part_b);

  CharList_free_array(&input_list);
  return 0;
}
