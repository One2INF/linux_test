#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

#include<stdio.h>

int main(void)
{
  printf("Program Starting...\r\n");
  (void)raise(SIGKILL);
  printf("Program End...\r\n");

  return 0;
}