#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int flag = 0;

int main(void)
{
  pid_t pid = fork();
  if(0 == pid)
  {
    sleep(3);
    printf("I am child process!, flag = %d\r\n", flag);
  }
  else
  {
    flag = 10;
    printf("I am parent process\r\n");
  }

  return 0;
}