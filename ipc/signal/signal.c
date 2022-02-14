#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

#include<stdio.h>

/*
 * 有名管道：通用进程间通信，
 * 也是阅后即焚的通信方式，因为在内核空间。
 * 必须两端同时打开，否则打开会阻塞。
 * 这是为了保证效率，内存及时释放，
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