#include <stdio.h>
#include <unistd.h>

int main()
{
	/* create & run child process - a duplicate of parent, but remember its return value */

	pid_t pid = fork();

	/* Both parent and child will execute the next line, but will have different value for pid. */

	printf("My pid is %d.\n", pid);


}
