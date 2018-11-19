#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("Hello\n");
	/* Create and run child process - a duplicate of parent */

	fork();

	/* both parent and child will execute the next line */
	printf("world.\n");


}
