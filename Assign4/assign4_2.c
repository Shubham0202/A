Q2 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
 
        int *ptr = (int *)malloc( sizeof(int));
	*ptr = 0;              
    printf("\nMemory fixed");
        free(ptr);
    
    return 0;
}