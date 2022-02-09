#include<stdio.h>
#include<unistd.h>

int main(void)
{
  char buff[128] = "hello linux!";
  //printf("%s", buff);
  //write(STDOUT_FILENO, buff, 128);
  while(1);

  return 0;
}