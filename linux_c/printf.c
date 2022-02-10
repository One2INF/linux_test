#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main(void)
{
  /* 字符 */
  printf("char:\t%c\r\n", 'a');
  unsigned char uc = 10;
  printf("unsigned char: %hhu\r\n", uc);

  /* 整型 */
  short int si = 10;
  printf("short int:\t%hd\r\n", si);
  unsigned short int usi = 10;
  printf("unsigned short int:\t%hu\r\n", usi);
  printf("int:\t%d\r\n", 10);

  printf("\r\n");

  /*
   * 分别显示：十六进制 和 八进制
   * short: %hx, %ho;
   * int: %x, %o;
   * long: %lx, %lo;
   * long long: %llw, %llo.
   */
  unsigned int i = 26;
  printf("printf %d in below format:\r\n"
         "%%x:\t%x\r\n"
         "%%X:\t%X\r\n"
         "%%o:\t%o\r\n"
         "%%#x:\t%#x\r\n"
         "%%#o:\t%#o\r\n",
         i,
         i, i, i, i, i);

  printf("\r\n");

  /* 在转换说明中只能用小写的常量后缀，建议使用小写 */
  printf("unsigned int:\t%u\r\n", 10u);            /* 10u or 10U */
  printf("long:\t%ld\r\n", 10l);                   /* 10l or 10L */
  printf("unsigned long:\t%lu\r\n", 10ul);         /* 10ul or 10UL or 10lu or 10LU */
  printf("long long:\t%lld\r\n", 10ll);            /* 10ll or 10LL */
  printf("unsigned long long:\t%llu\r\n", 10ull);  /* 10ull or 10ULL or 10llu or 10LLU */

  printf("\r\n");

  /* 布尔类型 */
  _Bool b = 1;
  printf("_Bool: %d\r\n", b);

  printf("\r\n");

  /*
   * C99/C11 feature: inttypes.h stdint.h
   * 精确宽度整数类型：int32_t；
   * 最小整数类型：int_least8_t；
   * 最快最小整数类型：int_fast8_t；
   * 最大整数类型：intmax_t。
   */
  uint32_t u32 = 10;
  printf("uint32_t:\t%"PRId32"\r\n", u32);

  printf("\r\n");
  
  /* 浮点，注意精度损失 */
  printf("float:\t%f\r\n", 1.6777217e+7f);         /* or 1.6777217e+7F */
  printf("double:\t%lf\r\n", 0xa.1fp10);           /* 十六进制表示浮点数（C99） */
  printf("long double:\t%Lf\r\n", 1.6777217e+7l);  /* or 1.6777217e+7L */
 
  printf("\r\n");

  /*
   * 分别显示 十六进制 和 指数形式
   * float: %a %e;
   * double: %la %le;
   * long double: %La %Le.
   */
  double d = 16777217.0;
  printf("printf %lf in below format:\r\n"
         "%%e:\t%e\r\n"
         "%%E:\t%E\r\n"
         "%%a:\t%a\r\n"
         "%%A:\t%A\r\n",
         d,
         d, d, d, d);

  return 0;
}