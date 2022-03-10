#include<stdio.h>

int add(int a, int b)
{
  int and, xor;

  do{
    xor = a ^ b;
    and = (a & b) << 1;
    a = xor;
    b = and;
  }
  while(and);

  return xor;
}

int main(void)
{
  /* 验证 -a 等于 a 取反加一 */
  for(int a = 0; a < __INT_MAX__; ++a)
    if(a + ~a + 1 != 0)
      printf("a: %d, ~a + 1: %d\r\n", a, ~a + 1);

  printf("10 + 19: %d\r\n", add(10, 19));

  return 0;
}
