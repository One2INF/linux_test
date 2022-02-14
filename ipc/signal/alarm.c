#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

#include<stdio.h>

int main(void)
{
  unsigned int alarm_second = 3;
  printf("Set alarm: %u second\r\n", alarm_second);
  (void)alarm(alarm_second);

  int sleep_time_count = 0;
  while(1)
  {
    sleep(1);
    printf("sleep: %d\r\n", ++sleep_time_count);
  }

  printf("Program End...\r\n");

  return 0;
}