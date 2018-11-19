#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Calling execl...\n\n");
	execl("/bin/cat", "cat", "./03.c", NULL);
	printf("Exiting!\n");
}


