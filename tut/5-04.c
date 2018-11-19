// Multiprocessing (Continued)

#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Calling execl... \n\n");
	execl("/bin/ls", "ls", NULL);
	printf("Exiting!");
}


