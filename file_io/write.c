#include<unistd.h>

int main(void)
{
  write(1, "hello world!\r\n", 128);

  return 0;
}
