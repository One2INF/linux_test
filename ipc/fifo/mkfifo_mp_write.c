#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>

/*
 * 有名管道：通用进程间通信，
 * 也是阅后即焚的通信方式，因为在内核空间。
 * 必须两端同时打开，否则打开会阻塞。
 * 这是为了保证效率，内存及时释放，
 */

int main(void)
{
  const int BUFFER_SIZE = 128;
  char buff[BUFFER_SIZE];

  int ret = mkfifo("named_pipe", 0664);
  if(-1 == ret)
  {
    /* ignore this, either read or write can mkfifo */
    printf("mkfifo() failed: %s!\r\n", strerror(errno));
  }

  int pipe_id = open("named_pipe", O_WRONLY);
  if(-1 == pipe_id)
  {
    printf("open named pipe failed: %s", strerror(errno));
    return -1;
  }

  printf("input the text to be writen in pipe: ");
  (void)fgets(buff, BUFFER_SIZE, stdin);

  int iWriteNum = write(pipe_id, buff, strlen(buff) + 1);  /* strlen() + 1 for writing '\0' to pipe */
  printf("parent process write %d B to pipe!\r\n", iWriteNum);
  close(pipe_id);

  return 0;
}