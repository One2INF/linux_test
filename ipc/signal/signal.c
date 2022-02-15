#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

#include<stdio.h>

/*
 * 信号：
 * signal(SIGUSR1, SIGIGN): 忽略信号；
 * signal(SIGUSR1, SIGDEL): 默认方式处理；
 * signal(SIGUSR1, SIGDFL): 自定义方法处理。
 */

void MySignalHandle(int signum)
{
  printf("pid: %d signal recieved: %d\r\n", getpid(), signum);
}

int main(void)
{
  signal(SIGUSR1, MySignalHandle);

  pid_t pid = fork();
  if(0 == pid)  /* child process */
  {
    while (1)
    {
      pause();
      sleep(1);
      kill(getppid(), SIGUSR1);
    }
  }
  else  /* parent process */
  {
    while (1)
    {
      sleep(1);
      kill(pid, SIGUSR1);
      pause();
    }
  }

  return 0;
}