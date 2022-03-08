#include<stdio.h>

int main(void)
{
  int *p;
  const int n = 10;

  printf("Before\t: n = %d\r\n", n);
  p = (int *)&n;
  *p = 11;
  printf("After\t: n = %d\r\n", n);

  return 0;
}
