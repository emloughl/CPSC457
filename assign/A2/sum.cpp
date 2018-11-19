/*
 * CPSC 457 - Operating Systems
 * Student Name: Evan Loughlin
 * UCID: 00503393
*/

#include <stdio.h>
#include <cstdlib>

#include <pthread.h>
#include <iostream>

#define MAX_NUMS 100000

using namespace std;

long ceil = 0;
long finSec = 0;
long sum = 0;
long T = 0;
long nums[MAX_NUMS];


void *adder(void * num){

    long tNum = (long) num;
    tNum = tNum + 1;
    long tot = 0, begin = 0, end = 0; // tot is the total of each thread. begin is the index at beginning
	// end is the index at the end

	
    if(tNum == T){
        end = ceil*(tNum-1) + finSec;
    } else
	{
        end = ceil * tNum;
    }
	
    // Check if it's the first thread.
    if(tNum == 1)
	{
        begin = 0;
    } else 
	{
        begin = (tNum-1) * ceil;
    }
	
	
    // Summing values from the array
    for (begin; begin < end; begin++){
        tot += nums[begin];
    }
	
	// Add the thread's total to the overall global sum variable.
    sum += tot; 
	
	
	// Print to standard output:
    printf("Thread %ld: %ld\n", tNum, tot);
    pthread_exit(0);
}

int main(int argc, char *argv[]){
    sum = 0;
    if(argc != 3){
        cout << "Incorrect file usage. Use:   ./sum <filename> <number_of_threads>" << endl;
        exit(-1);
    }

    // Assign number of threads from command line arguments:
    T = atol(argv[2]);
    const char * filename = argv[1];
    

    // Opening file from system
    FILE* fp;
    if((fp = fopen(filename, "r")) == NULL)
    {
        cout << "Could not find the file: " << argv[1] <<  endl;
        exit(-1);
    }

    int num;
    int j = 0;

    // Store values from filestream into an array.
    while(fscanf(fp, "%d", &num) != EOF){
        nums[j] = num;
        j++;
    }

	
    // Calculating the ceiling, and incremental amounts of each section.
    ceil = (long)j / T;
    finSec = (long)j - (ceil*(T-1));

    printf("%ld ceiling value.\n", ceil);

    // Loop to create threads
    pthread_t threads[T];
    for(long i = 0; i < T; i++){
        if(pthread_create(&threads[i], NULL, adder, (void *)i) != 0){
            cout << "Error: Invalid thread creation." << endl;
            exit(-1);
        }
    }

    // Join the remaining threads.
    for(long i = 0; i < T; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Sum = %ld\n", sum);
    return 0;
}
