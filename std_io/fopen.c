#include<stdio.h>

int main(void)
{
  FILE *fp = fopen("file.txt", "a");
  if(NULL == fp)
  {
    printf("fopen file.txt failed!\r\n");
  }

  printf("fopen file.txt successed!\r\n");

  fclose(fp);

  return 0;
}