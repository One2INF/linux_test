#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int ret = system("ls -al");
  printf("ret: %d\r\n", ret);

  ret = system("grep");
  printf("ret: %d\r\n", ret);
  
  return 0;
}