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
  printf("toosmall: %f\r\n", toosmall);

  /* nan = not a number */
  printf("asin(1.1): %lf\r\n", asin(1.1L));

  return 0;
}