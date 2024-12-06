Ass4

Q1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#define SHM_KEY 1
#define SHM_SIZE 1024
int main()
{

int shm_id = shmget(SHM_KEY,SHM_SIZE,IPC_CREAT | 0666);
char *str;
str= (char*) shmat( shm_id, NULL, 0);

if(shmat <0)
{
printf("Error While Attaching\n");
}

pid_t pid = fork();
	if(pid ==0)
	{
		sleep(1);
	strcpy(str,"hello to Parent\n");
	printf("Msg from parent%s",str);
	}
	else if(pid>0)
	{
		strcpy(str,"hello to child");
		printf("MSg from parent:%s\n",str);
		sleep(1);
	}
}