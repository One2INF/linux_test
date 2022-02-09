#include<stdio.h>

int main(void)
{
  const int a = 1;
  int* p = (int*)&a;
  *p = 100;

  printf("a is %d\r\n", a);

  return 0;
}
