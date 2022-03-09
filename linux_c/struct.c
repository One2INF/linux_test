#include<stdio.h>

#define LEN     16

struct personal
{
  char first_name[LEN];
  char last_name[LEN];
  int age;
};

struct personal guys[2] =
{
  {
    "zhengjie",
    "shi",
    28
  },
  {
    "junsu",
    "hu",
    28
  }
};

int main(void)
{
   struct personal *him = guys;

   printf("NO.\tfirst name\tlast name\tage\r\n");
   for(int i = 0; i < sizeof(guys) / sizeof(struct personal); ++i, ++him)
   {
     printf("#%-7d%-16s%-16s%-8d\t\r\n", i, him->first_name, him->last_name, him->age);
   }

  return 0;
}