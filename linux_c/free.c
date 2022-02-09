#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int a;
  int* p = &a;
  free(p);
  free(p);

  int *p_null = NULL;
  free(p_null);
  
  int *p1 = malloc(sizeof(int));
  free(p1);
  free(p1);

  return 0;
}