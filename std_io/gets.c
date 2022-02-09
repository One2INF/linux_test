#include<stdio.h>

int main(void)
{
  char gets_buff[8];
  
  char *p = gets(gets_buff);
  if(NULL == p)
  {
    printf("gets failed!");
    return -1;
  }

  puts(gets_buff);
  
  return 0;
}
