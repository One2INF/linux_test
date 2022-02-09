#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(void)
{
  int fd = open("file.txt", O_RDWR | O_APPEND);
  if(fd < 0)
  {
    printf("open file.txt failed: %s!\r\n", strerror(errno));
    return 0;
  }

  char write_buff[128] = "hello linux!\r\n";
  ssize_t count = write(fd, write_buff, 128);
  printf("%ld \tbis(s) writen!\r\n", count);

  char read_buff[128];
  count = read(fd, read_buff, 128);
  printf("%ld \tbit(s) readed!\r\n", count);

  close(fd);

  return 0;
}
