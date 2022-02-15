#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<signal.h>

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define BUFF_SIZE    128

typedef struct
{
  pid_t write_pid;
  pid_t read_pid;
  char buff[BUFF_SIZE];
}SHM_DATA_ST;

void Usr1SignalHandle(int signum)
{
  return;
}

int main()
{
  key_t key = ftok("/proc/cpuinfo", 'a');
  if(key == -1)
  {
    printf("ftok() failed: %s\r\n", strerror(errno));
    return -1;
  }

  const size_t SHM_SIZE = sizeof(SHM_DATA_ST);
  int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0664);
  if(shmid == -1)
  {
    printf("shmget() failed: %s\r\n", strerror(errno));
    return -2;
  }

  SHM_DATA_ST *p = (SHM_DATA_ST *)shmat(shmid, NULL, 0);
  if(p == (void *)-1)
  {
    printf("shmat() failed: %s\r\n", strerror(errno));
    return -3;
  }

  printf("Shared memory attached from %p to %p\r\n", (void *)p, (void *)p + SHM_SIZE);  

  signal(SIGUSR1, Usr1SignalHandle);

  p->write_pid = getpid();
  /* wait read process start */
  pause();

  int time_count = 5;
  while(--time_count)
  {
    snprintf(p->buff, BUFF_SIZE, "Hello linux %d", time_count);
    printf("write to shared memory: %s\r\n", p->buff);

    /* notice reader to read */
    kill(p->read_pid, SIGUSR1);
    sleep(1);
  }

  kill(p->read_pid, SIGKILL);

  int ret = shmctl(shmid, IPC_RMID, NULL);
  if(ret == -1)
  {
    printf("shmctl() delete shared memory failed: %s\r\n", strerror(errno));
    return -4;
  }

  return 0;
}