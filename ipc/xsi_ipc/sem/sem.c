#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdlib.h>

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>


int main(void)
{
  int semid = semget(IPC_PRIVATE, 3, IPC_CREAT | 0664);
  if(semid == -1)
  {
    printf("semget() failed: %s\r\n", strerror(errno));
    return -1;
  }

  struct sembuf sop;
  int i = 4;
  int ret;
  pid_t pid = fork();
  if(pid) /* parent process */
  {
    sop.sem_num = 0;  /* Operate on semaphare 0 */
    sop.sem_op = -1;  /* Decrement value by one */
    sop.sem_flg = 0;
    ret = semop(semid, &sop, 1);
    if(ret == -1)
    {
      printf("semop() failed: %s\r\n", strerror(errno));
      return -2;
    }

    while(--i)
    {
      printf("parent hello linux: %d\r\n", i);
      sleep(1);
    }

    exit(EXIT_SUCCESS);
  }
  else /* child process */
  {
    while(--i)
    {
      printf("child hello linux: %d\r\n", i);
      sleep(1);
    }

    sop.sem_num = 0;  /* Operate on semaphare 0 */
    sop.sem_op = 1;   /* Increment value by one */
    sop.sem_flg = 0;
    ret = semop(semid, &sop, 1);
    if(ret == -1)
    {
      printf("semop() failed: %s\r\n", strerror(errno));
      return -2;
    }

    exit(EXIT_SUCCESS);
  }

  ret = semctl(semid, 0, IPC_RMID);
  if(ret == -1)
  {
    printf("semctl() delete semaphore failed: %s\r\n", strerror(errno));
    return -2;
  }

  return 0;
}