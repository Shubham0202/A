
Q? signal

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


pid_t child_pid;


void sigint_handler(int sig) 
{
    printf("\nReceived SIGINT. Stopping child process...\n");
    kill(child_pid, SIGSTOP);
}

void sigterm_handler(int sig) 
{
    printf("\nReceived SIGTERM. Terminating child process...\n");
    kill(child_pid, SIGTERM);
    wait(NULL);
    exit(0);
}

void child_process() 
{
    while (1) 
    {
        printf("\nPROCESS RUNNING >>");
        fflush(stdout);
        sleep(2);
    }
}

int main() 
{

    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigterm_handler);

    child_pid = fork();

    if (child_pid < 0) 
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) 
    {
        child_process();
    } 
    else 
    {
        while (1) 
        {
            printf("Enter 'r' to resume or 'q' to quit: ");
            char input;
            scanf(" %c", &input);

            if (input == 'r') 
            {
                kill(child_pid, SIGCONT);
            } else if (input == 'q') {
                kill(child_pid, SIGTERM);
                wait(NULL);
                break;
            } 
            else 
            {
                printf("INVALID INPUT\n");
            }
        }
    }

    return 0;
}
