
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep

void *print_hello_world(void *unused) 
{
while(1)
	{
	printf("Hello World.\n");
	sleep(1);
	}
return NULL;
}



int main (int argc, char *argv[])
{
pthread_t mythread;
printf("Main here ...\n");
pthread_create(&mythread, NULL, &print_hello_world, NULL); // This creates a new thread based on the function print_hello_world

while(1)
{
	printf("Hello CPSC\n");
	sleep(1);
}

//int i;
//for(i = 0; i < 1000; i++)
//	printf("%d\n",i);

return 0;

}
