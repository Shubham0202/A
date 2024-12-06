Q.? Memory Leaked

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
 
        int *ptr = (int *)malloc(sizeof(int));
	*ptr = 0;    
    printf("\nMemory leaked");
    
    return 0;
}
