/*
 * Program to check ch06pr05.md
 */

#include <stdio.h>

int main(void) {
  int i, j;
  int numbers[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for (j = 0; j < 10; ++j) {
    for (i = 0; i < j; ++i) {
      numbers[j] += numbers[i];
    }
  }
  for (j = 0; j < 10; ++j) {
    printf("%i ", numbers[j]);
  }
  printf("\n");

  return 0;
}
