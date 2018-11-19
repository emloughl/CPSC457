// Signals are a way of sending simple messages to processes.
// Most of these messages are already defined and can be found in <linux/signal.h>

// Signal is a notification sent to a process to notify it of some event.
// Signal has an integer number that represents it, and symbolic name.

// Example:
// signal SIGALRM (numeric value is 14) caused also by alarm clock
//


// Catch the SIGINT signal

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
	if (signo == SIGINT)
		printf("OUCH - I got signal\n");
}

int main(void)
{
	//if (signal(SIGINT, sig_handler) == SIG_ERR)
	//	printf("\nCan't catch SIGINT\n");

	while(1)
	{
		printf("Hi \n");
		sleep(1);	
	}

	return 0;

}
