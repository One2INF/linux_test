#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define BUFF_SIZE        128
#define PARENT_TYPE_ID     1

typedef struct
{
  long type;
  char text[BUFF_SIZE];
}MSG_DATA_ST;

int main()
{
  int msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
  if(msgid == -1)
  {
    printf("msgget() failed: %s\r\n", strerror(errno));
    return -1;
  }

  char buff[BUFF_SIZE];
  MSG_DATA_ST MsgData;
  pid_t pid = fork();
  if(pid) /* parent process */
  {
    while (1)
    {
      MsgData.type = PARENT_TYPE_ID;
      printf("input text to msg: ");
      fgets(MsgData.text, BUFF_SIZE, stdin);
      msgsnd(msgid, &MsgData, BUFF_SIZE, 0);
      sleep(1);
    }
  }
  else /* child process */
  {
    while(1)
    {
      msgrcv(msgid, &MsgData, BUFF_SIZE, PARENT_TYPE_ID, 0); 
      printf("read from msg: %s", MsgData.text);
    }
  }

  int ret = msgctl(msgid, IPC_RMID, NULL);
  if(ret == -1)
  {
    printf("msgctl() delete shared memory failed: %s\r\n", strerror(errno));
    return -2;
  }

  return 0;
}