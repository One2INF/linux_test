#include<stdio.h>

int main(void)
{
  printf("int\t\tsize: %lu\r\n", sizeof(int));
  printf("int*\t\tsize: %lu\r\n", sizeof(int*));

  printf("long\t\t\tsize: %lu\r\n", sizeof(10L));
  printf("unsigned long\t\tsize: %lu\r\n", sizeof 10UL);
  printf("long long\t\tsize: %lu\r\n", sizeof 10LL);
  printf("unsigned long long\tsize: %lu\r\n", sizeof 10ULL);

  return 0;
}
