#include<stdio.h>

int g_a = 0;
int main(void)
{
  static int s_a = 0;
  int a = 10;

  printf("address of main: %p\r\n", main);
  printf("address of g_a : %p\r\n", &g_a);
  printf("address of a   : %p\r\n", &a);
  printf("address of s_a : %p\r\n", &s_a);

  return 0;
}