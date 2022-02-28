#include<stdio.h>

/*
 * 该例子说明当 scanf 遇到不匹配的参数类型时，
 * 会将读取的参数放回输入队列，不会对当前的参数产生副作用。
 */

int main(void)
{
  printf("input a string to begain testing!\r\n");
  int i = 100;
  scanf("%d", &i);
  printf("i: %d\r\n", i);

  char str[128];
  scanf("%s", str);
  printf("str: %s\r\n", str);

  return 0;
}