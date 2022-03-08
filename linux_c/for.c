#include<stdio.h>

int main(void)
{
  for(int i = 0, j = 0; i < 10; ++i, ++j)
  {
    printf("[i, j]: [%2d, %2d]\r\n", i, j);
  }

  return 0;
}