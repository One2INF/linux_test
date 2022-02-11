#include<unistd.h>

#include<stdio.h>

/*
 * printf 输出存在行缓存，遇到
 * buffer full, need input(e.g. scanf()), '\n',
 * force flush(e.g. fflush()) or program ends 时，
 * 才会发送缓存数据。
 */

int main(void)
{
  printf("1-hello world\n");
  printf("2-hello world");
  sleep(1);
  fflush(stdout);

  /* 
   * the size of buffer is 1025 on my linux machine.
   * it's a strange number, why not 1024? or anything I didn't consider.
   */
  int output_size;
  printf("\r\ninput the size to output: ");
  scanf("%d", &output_size);

  while(--output_size)
  {
    printf("c");
  }

  sleep(1);

  return 0;
}