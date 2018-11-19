// Using signals by threads

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

static int alarm_fired = 0;

void ding(int sig)
{
	alarm_fired = 1;
}


int main()
{
	pid_t pid;
	cout << "Alarm application starting.\n";

	pid = fork();

	if(pid == 0)
	{
		/*child*/
		sleep(3);
		kill(getppid(), SIGALRM);
		exit(0);
	}

	/*If we get here we the parent process*/
	cout << "Waiting for alarm to go off \n";
	(void) signal(SIGALRM, ding);
	pause();
	if(alarm_fired)
		printf("Ding! \n");

	cout << "Done\n";
	cout << "alarm_fired = " << alarm_fired << endl;
	exit(0);
}

/*
 Comment the pause() line and check the result
 Comment the Sleep(3) line and check the result

*/
