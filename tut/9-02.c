#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
	if (signo == SIGINT)
		printf("I can catch you :) \n");
	else if (signo == SIGKILL)
		printf("received SIGKILL\n");
	else if (signo == SIGSTOP)
		printf("received SIGSTOP\n");
}

int main(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\n Can't catch SIGKILL\n");
	if (signal(SIGKILL, sig_handler) == SIG_ERR)
		printf("\n Can't catch SIGKILL\n");
	if (signal(SIGSTOP, sig_handler) == SIG_ERR)
		printf("\n Can't catch SIGSTOP\n");

// A long long wait so that we can easily issues a signal to this process

while(1)
sleep(1);

return 0;

}
