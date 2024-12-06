Q2.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void atexitFunction(){
	printf("cleanUp 1\n");
}
void second(){
	printf("cleanUp 2\n");
	
}
int main()
{
	atexit(second);
	atexit(atexitFunction);
	printf("MAIN FUNCTION\n");
 
}
