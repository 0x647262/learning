/*
 * Modify the repdigit.c program of Section 8.1 so that it prints a table
 * showing how many times each digit appears in the number:
 *
 *      Enter a number: 41271092
 *      Digit:              0 1 2 3 4 5 6 7 8 9
 *      Repeated digit(s):  1 2 2 0 1 0 0 1 0 1
 */

#include <stdio.h>

int main(void) {
  int duplicates[10] = {0};
  int digit = 0;
  int empty = 0;
  long n = 0;

  printf("Enter a number: ");
  scanf("%ld", &n);
  while (n > 0) {
    digit = n % 10;
    duplicates[digit] += 1;
    n /= 10;
  }

  for (int i = 0; i < 10; i += 1) {
    empty += duplicates[i];
  }
  if (empty == 0) {
    printf("No repeated digits\n");
  } else {
    printf("Digit:\t\t");
    for (int i = 0; i < 10; i += 1) {
      printf("%d ", i);
    }
    printf("\nOccurances:\t");
    for (int i = 0; i < 10; i += 1) {
      printf("%d ", duplicates[i]);
    }
    printf("\n");
  }
  return 0;
}
