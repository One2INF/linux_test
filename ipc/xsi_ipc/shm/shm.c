#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<signal.h>

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define BUFF_SIZE    128
#define SHM_SIZE     128

void Usr1SignalHandle(int signum)
{
  return;
}

int main()
{
  int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0664);
  if(shmid == -1)
  {
    printf("shmget() failed: %s\r\n", strerror(errno));
    return -1;
  }

  char *p = (char *)shmat(shmid, NULL, 0);
  if(p == (void *)-1)
  {
    printf("shmat() failed: %s\r\n", strerror(errno));
    return -2;
  }

  printf("Shared memory attached from %p to %p\r\n", (void *)p, (void *)p + SHM_SIZE);
  
  pid_t pid = fork();
  if(pid) /* parent process */
  {
    char str[128] = "hello linux 0";
    strncpy(p, str, strlen(str) + 1);
    char ch = '0';
    do
    {
      sleep(1);
      p[strlen(str) - 1] = ++ch;
      kill(pid, SIGUSR1);
    }while(ch != '3');

    kill(pid, SIGKILL);
  }
  else /* child process */
  {
    signal(SIGUSR1, Usr1SignalHandle);
    while(1)
    {
      printf("read from shm: %s\r\n", p);
      pause();
    }
  }

  int ret = shmctl(shmid, IPC_RMID, NULL);
  if(ret == -1)
  {
    printf("shmctl() delete shared memory failed: %s\r\n", strerror(errno));
    return -3;
  }

  return 0;
}