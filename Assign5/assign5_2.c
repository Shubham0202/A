
Q2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void child_process()
{
	while(1)
	{
	printf("\nPROCESS RUNNING >>");
	fflush(stdout);
	sleep(2);
	}
}


int main() {
    	pid_t pid;
    	int i;
    	char input ;
    	pid = fork();
	
    	if(pid == 0) 
   	{
   	 child_process();
	}
	else
	{
	
		while(1)
		{
			
			
			printf("Enter s r q\n");
			scanf(" %c" , &input);
			
			
			if(input == 's')
			{
				kill(pid , SIGSTOP);
			}
			else if(input =='r')
			{
				kill(pid , SIGCONT);
			}
			else if(input == 'q')
			{
				kill(pid , SIGTERM);
				wait(NULL);
				break;
			}
			else
			{
				printf("INVALID INPUT\n ");
				
			}
			
		}
	}
	return 0;
}