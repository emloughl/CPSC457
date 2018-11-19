#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void * tnum)
{
	printf("I am thread number %d\n", *(int*)tnum);
}

int main(int argc, char *argv[])
{
pthread_t threads[NUMBER_OF_THREADS];
int status, i;

for(i = 0; i < NUMBER_OF_THREADS; i++)
{
pthread_create(&threads[i], NULL, print_hello_world, (void *) &i);

}

for (i = 0; i < NUMBER_OF_THREADS; i++)
	pthread_join(threads[i], NULL);
}


