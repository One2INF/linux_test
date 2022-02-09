#include<stdio.h>

#define DAY1 "Monday"

#define TO_STRING(x) #x
#define SPLICE(x)   TO_STRING(DAY##x)

int main(void)
{
  int var;
  printf("TO_STRING: %s\r\n", TO_STRING(var));
  printf("SPLICE: %s\r\n", SPLICE(a+b));

  return 0;
}