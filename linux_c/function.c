#include<stdio.h>

int main(void)
{
  int a[1000];
  void (*p)(void) = (void(*)(void))a;
  p();
//  printf("return of p: %d", p());

  return 0;
}