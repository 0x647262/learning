/*
 * Simplify Programming Project 1 by taking advantage of the fact that an array
 * name can be used as a pointer
 *
 * ##### Spec:
 *
 * Write a program that reads a message, then prints the reversal of the
 * message:
 *
 *      Enter a message: Don't get mad, get even.
 *      Reversal is: .neve teg ,dam teg t'noD
 *
 * Hint: Read the message one character at a time (using getchar()) and store
 * the characters in an array. Stop reading when the array is full, or the
 * character read is '\n'.
 */

#include <stdio.h>

#define LENGTH 81

void read_message(int *array, int *c);
void reverse_message(const int *array, int *c);

void read_message(int *array, int *c) {
  while ((array[*c] = getchar()) != '\n') {
    *c += 1;
    if (*c == LENGTH) {
      break;
    }
  }
  *c -= 1;
}

void reverse_message(const int *array, int *c) {
  while (*c != -1) {
    printf("%c", *(array + *c));
    *c -= 1;
  }
  printf("\n");
}

int main(void) {
  int message[LENGTH] = {0};
  int len = 0;
  int *chars = &len;

  read_message(message, chars);
  reverse_message(message, chars);

  return 0;
}
