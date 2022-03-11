#include<stdio.h>

/*
 * 添加 #include<stdalign.h>
 * alignas 和 alignof 分别作为 _Alignas 和_Alignof 的别名，
 * 与 C++ 兼容。
 */

struct data
{
  _Alignas(int) char ch;
};

struct array_data
{
  char i;
  _Alignas(8) char a[4];
};

int main(void)
{
  printf("alignas(int): %zd\r\n", _Alignof(int));
  printf("sizeof struct data: %zd\r\n", sizeof(struct data));
  printf("sizeof struct array_data: %zd\r\n", sizeof(struct array_data));

  return 0;
}
