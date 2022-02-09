#include<stdio.h>

int main(void)
{
  char* buff = "123456";
  int a[10];
  int *p = a;
  int (*pa)[10] = a;

  printf("size of a : %lu\r\n", sizeof(a));
  printf("size of p : %lu\r\n", sizeof(p));
  printf("size of pa: %lu\r\n", sizeof(pa));

  return 0;
}