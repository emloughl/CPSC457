#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

#define NUMBER_OF_THREADS 10

void *print_hello_world(void * tnum) 
{
	printf("Hello World. Greetings from thread %d.\n", *(int *)tnum);
}

int main(int argc, char *argv[]) 
{
	pthread_t threads[NUMBER_OF_THREADS];
	int status, i;

	for (i = 0; i < NUMBER_OF_THREADS; i++) 
	{
		status = pthread_create(&threads[i], NULL, print_hello_world, (void *) &i);
		if (status != 0) 
		{
		printf("Oops, pthread_create returned error code %d.\n", status);
		exit(-1);
		}

	}

	for(i = 0; i < NUMBER_OF_THREADS; i++)
		pthread_join(threads[i], NULL);
}


	

