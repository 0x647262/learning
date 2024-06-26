/*
 * Even Fibonacci numbers
 *
 * Problem 2
 * Published on Friday, 19th October 2001, 06:00 pm; Difficulty rating: 5%
 *
 * Each new term in the Fibonacci sequence is generated by adding the previous
 * two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 * 		1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 *
 * TODO: util.h - Add is_even function
 */

#include <stdio.h>

#define MAX_FIBONACCI_TERM 4000000

int fib(int n);

int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return (fib(n - 1) + fib(n - 2));
  }
}

int main(void) {
  int sum = 0;
  int n = 1;

  while (fib(n) <= MAX_FIBONACCI_TERM) {
    if (fib(n) % 2 == 0) {
      sum += fib(n);
    }
    n += 1;
  }
  printf("Total: %d\n", sum);

  return 0;
}
