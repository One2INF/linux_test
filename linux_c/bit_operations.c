#include<stdio.h>

int add(int a, int b)
{
  int carry, sum;

  do{
    sum = a ^ b;
    carry = (a & b) << 1;
    a = sum;
    b = carry;
  }
  while(carry);

  return sum;
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
