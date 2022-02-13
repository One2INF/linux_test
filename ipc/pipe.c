#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

#include<stdio.h>
#include<errno.h>
#include<string.h>

/*
 * 无名管道：亲缘进程间通信，
 * 一次性阅后即焚的通信方式。
 */

int main(void)
{
  /*
   * filedes[0]: read file id; 
   * filedes[1]: write file id.
   */
  int filedes[2]; 
  
  int BUFFER_SIZE = 128;
  char buff[BUFFER_SIZE];
  
  int ret = pipe(filedes);
  if(-1 == ret)
  {
    printf("pipe() failed: %s!\r\n", strerror(errno));
    return -1;
  }

  pid_t pid = fork();
  if(0 == pid)
  {
    close(filedes[1]);
    int iReadNum = read(filedes[0], buff, BUFFER_SIZE);
    printf("child process read %d B from pipe: %s", iReadNum, buff);
    close(filedes[0]);

    exit(EXIT_SUCCESS);
  }
  else
  {
    close(filedes[0]);
    printf("input the text to be writen in pipe: ");
    (void)fgets(buff, BUFFER_SIZE, stdin);

    int iWriteNum = write(filedes[1], buff, strlen(buff) + 1);  /* strlen() + 1 for writing '\0' to pipe */
    printf("parent process write %d B to pipe!\r\n", iWriteNum);
    close(filedes[1]);
    exit(EXIT_SUCCESS);
  }

  return 0;
}