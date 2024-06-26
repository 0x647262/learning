/*
 * Function to calculate the area and circumference of a circle, and the volume
 * of a given radius.
 */

#include <stdio.h>

#define PI 3.141592654

double area(double r);
double circumference(double r);
double volume(double r);

double area(double r) { return PI * r * r; }

double circumference(double r) { return 2.0 * PI * r; }

double volume(double r) { return 4.0 / 3.0 * PI * r * r * r; }

int main(void) {
  printf("radius = 1.00: %.4f\t%.4f\t%.4f\n", area(1.0), circumference(1.0),
         volume(1.0));

  printf("radius = 4.98: %.4f\t%.4f\t%.4f\n", area(4.98), circumference(4.98),
         volume(4.98));

  return 0;
}
