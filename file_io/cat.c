#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdbool.h>

int main(int argc, char** argv)
{
  if(argc <= 1)
  {
    printf("file name should be passed!\r\n"
           "usage: ./cat path_filename\r\n"
           " e.g.: ./cat ./file.txt\r\n");
    return -1;
  }
 
  int fd = open(argv[1], O_RDONLY);
  if(fd < 0)
  {
    printf("open %s failed: %s!\r\n", argv[1], strerror(errno));
    return 0;
  }

  ssize_t count = 0;
  char read_buff[128];
  while(true)
  {
    count = read(fd, read_buff, 128);
    if(0 == count)
      break;
 
    write(STDOUT_FILENO, read_buff, count);
  }

  close(fd);

  return 0;
}
