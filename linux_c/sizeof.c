#include<stdio.h>

/*
 * sizeof is C's inner operator, not function.
 * use %zd format to print size_t.(C99/C11)
 * if not use %u or %lu instead.
 */

int main(void)
{
  printf("int\t\tsize: %zd\r\n", sizeof(int));
  printf("int*\t\tsize: %zd\r\n", sizeof(int*));

  printf("long\t\t\tsize: %zd\r\n", sizeof(10L));
  printf("unsigned long\t\tsize: %zd\r\n", sizeof 10UL);
  printf("long long\t\tsize: %zd\r\n", sizeof 10LL);
  printf("unsigned long long\tsize: %zd\r\n", sizeof 10ULL);

  return 0;
}
