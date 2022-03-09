#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN     32

struct flex
{
  char header[LEN];
  int size;
  char data[];
};

void showFlex(const struct flex *p)
{
  printf("header: %s\r\n"
         "size  : %d\r\n"
         "data  : %s\r\n",
         p->header, p->size, p->data);
}

int main(void)
{
  char str1[LEN] = "I am szj!";
  struct flex *pf1 = malloc(sizeof(struct flex) + strlen(str1));

  strncpy(pf1->header, "Header1", LEN);
  pf1->size = sizeof(*pf1) + strlen(str1);
  strncpy(pf1->data, str1, strlen(str1));

  showFlex(pf1);
  free(pf1);

  char str2[LEN] = "Now I am szj plus!";
  struct flex *pf2 = malloc(sizeof(struct flex) + strlen(str2));

  strncpy(pf2->header, "Header2", LEN);
  pf2->size = sizeof(*pf2) + strlen(str2);
  strncpy(pf2->data, str2, strlen(str2));

  printf("\r\n");
  showFlex(pf2);
  free(pf2);

  return 0;
}