Q2. 
//open file and sleep for 15sec.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{

    FILE* fp= fopen("readDir.c","r");
    char ch;
    if(fp==NULL)
    printf("File Not Opened");
    
    while((ch = fgetc(fp)) !=EOF)
    {
        putchar(ch);
    }
    sleep(15);
}