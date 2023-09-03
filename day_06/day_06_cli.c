#include <stdio.h>

#include "../common/CharList.h"
#include "day_06.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Missing input file!\n");
    return 1;
  }

  char *filename = argv[1];
  CharList input_list;
  CharList_init_array(&input_list, 2148);

  if (parse_input(&input_list, filename)) {
    return 1;
  }

  printf("%d\n", input_list.size);

  int part_a = day_6_part_a(&input_list);
  printf("Day 06 Part A:\t%d\n", part_a);

  int part_b = day_6_part_b(&input_list);
  printf("Day 06 Part B:\t%d\n", part_b);

  CharList_free_array(&input_list);
  return 0;
}
