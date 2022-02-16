#include<stdio.h>
#include<math.h>

/*
 * include math libs, use -lm to link.
 * e.g. gcc float.c -lm
 */

int main(void)
{
  /* float overflow */
  float toobig = 3.4e38 * 100.0f;
  printf("toobig: %e\r\n", toobig);

  /* float underflow */
  float toosmall = 3.4e-44 / 100.0f;
  printf("toosmall: %e\r\n", toosmall);

  /* nan = not a number */
  printf("asin(1.1): %lf\r\n", asin(1.1L));

  float a, b;
  b = 2.0e20 + 1.0;
  a = b - 2.0e20;
  printf("2.0e20 + 1.0 - 2.0e20: %f\r\n", a);

  return 0;
}