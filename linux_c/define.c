#include<stdio.h>

#define STRINGS "define's replacement body"    " is including entire reset of the line.\n" \
"I am the second line.\n"

int main(void)
{
  printf(STRINGS);

  return 0;
}