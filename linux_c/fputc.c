#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    fprintf(stderr, "Usage: %s filename\r\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *in;
  if((in = fopen(argv[1], "rb")) == NULL)
  {
    fprintf(stderr, "Can't open the file \"%s\"", argv[1]);
    exit(EXIT_FAILURE);
  }

  fprintf(stdout, "file text:\r\n");
  char ch;
  while((ch = fgetc(in)) != EOF)
  {
    fprintf(stdout, "%c|%3d\r\n", ch, ch);
  }

  return 0;
}
