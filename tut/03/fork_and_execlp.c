
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	
	pid = fork(); /* Create and run child process - a duplicate of parent. Both parent and child will execute the next line */

	if(pid < 0) { /* error occurred */ 
		fprintf(stderr, "Fork failed");
		exit(-1);
	}

	else if (pid == 0) { /* Child process */
		execlp("/bin/ls", "ls", "-1", NULL); /* Replace process with 'ls -l' */
	}
	else { /* Parent process will wait for the child to complete */
		printf("Waiting for child process %d\n", pid);
		wait(NULL);
		exit(0);
	}


}
