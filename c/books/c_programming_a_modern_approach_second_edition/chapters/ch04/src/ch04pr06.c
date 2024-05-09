/*
 * European countries use a 13-digit code, known as a European Article Number
 * (EAN) instead of the 12 digit Universal Product Code found in North America.
 * Each EAN ends with a check digit, just as a UPC does. The technique for
 * calculating the check digit is also similar:
 *
 *      Add the second, fourth, sixth, eighth, tenth, and twelfth digits.
 *      Add the first, third, fifth, seventh, ninth, and eleventh digits.
 *      Multiply the first sum by 3 and add it to the second sum.
 *      Subtract 1 from the total.
 *      Compute the remainder when adjusted total is divided by 10.
 *      Subtract the remainder from 9.
 *
 * For example, consider Gulluoglu Turkish Delight Pistachio & Coconut, which
 * has an EAN of 8691484260008. The first sum is 6 + 1 + 8 + 2 + 0 + 0 = 17 and
 * the second sum is 8 + 9 + 4 + 4 + 6 + 0 = 31. Multiplying the first sum by 3
 * and adding the second yields 82. Subtracting 1 gives 81. The remainder upon
 * dividing by 10 is 1. When the remainder is subtracted frim 9, the result is
 * 8, which matches the last digit of the original code. Your job is to modify
 * the upc.c program of section 4.1 so that it calculates the check digit for
 * an EAN. The user will enter the first 12 digits of the EAN as a single
 * number:
 *
 *      Enter the first 12 digits of an EAN: 8691484260008
 *      Check digit: 8
 */

#include <stdio.h>

int main(void) {
  int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12;
  int sum1, sum2;
  int check;

  printf("Enter the first 12 digits of your EAN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6,
        &i7, &i8, &i9, &i10, &i11, &i12);
  sum1 = i2 + i4 + i6 + i8 + i10 + i12;
  sum2 = i1 + i3 + i5 + i7 + i9 + i11;
  check = (sum1 * 3) + sum2;
  check = check - 1;
  check = check % 10;
  check = 9 - check;
  printf("Check digit: %d\n", check);

  return 0;
}
