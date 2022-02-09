#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
  pid_t pid = fork();
  if(0 == pid)
  {
    printf("I am child process!\r\n");
  }
  else
  {
    printf("I am parent process\r\n");
  }

  return 0;
}