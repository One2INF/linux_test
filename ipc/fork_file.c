#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main(void)
{
  int fd = open("file.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
  if(fd < 0)
  {
    printf("open file.txt failed\r\n");
    return -1;
  }

  printf("open file.txt successed, fd: %d\r\n", fd);

  pid_t pid = fork();
  if(0 == pid)
  {
    sleep(3);
    printf("I am child process!\r\n");

    char read_buff[128];
    int ret = read(fd, read_buff, 7);
    printf("child ret: %d, read_buff: %s", ret, read_buff);
  }
  else
  {
    write(fd, "hello\r\n", 7);
    printf("I am parent process\r\n");

    char read_buff[128];
    int ret = read(fd, read_buff, 7);
    printf("parent ret: %d, read_buff: %s", ret, read_buff);
  }

  close(fd);
  return 0;
}