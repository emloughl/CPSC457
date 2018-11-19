// This is for next tutorial. Using signals by threads

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int alarm_fired = 0;
void ding(int sig)
{
	alarm_fired = 1;
}

int main()
{
	pid_t pid;
	printf("Alarm application starting \n");

	pid = fork();
	switch(pid)
	{	
	case -1:
		/* Failure */
		perror("Fork failed");
		exit(1);

	case 0:
		/* Child */
		sleep(5);
		kill(getppid(), SIGALRM);
		exit(0);	
	}

/* If we get here we are the parent process */
printf(" Waiting for alarm to go off \n");
void signal(SIGALRM, ding);

pause();
if(alarm_fired) printf("Ding! \n");

printf("done\n");
exit(0);



}
