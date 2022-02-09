#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(void)
{
  int fd = open("file.txt", O_CREAT | O_EXCL, 0777);
  if(fd < 0)
  {
    printf("open file.txt failed: %s!\r\n", strerror(errno));
    return 0;
  }

  printf("open file.txt successed!\r\n");

  close(fd);

return 0;
}