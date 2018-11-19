#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For Sleep

void *print_hello_world(void *unused)
{

while(1)
	{
	printf("Hello World\n");
	sleep(1);
	}
	
return NULL;
}


int main(int argc, char *argv[])
{
pthread_t mythread;
printf("Main here... \n");
pthread_create(&mythread, NULL, &print_hello_world, NULL);

while(1)
{
 printf("Hello CPSC\n");
 sleep(1);

}

return 0;
}
