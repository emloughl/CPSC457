// Assignment 3 - Multithreading
// Evan Loughlin
// UCID 00503393
// Date: Mar 11 2018
// CPSC 457 - Operating Systems
//
/// compile with:
///   $ g++ countPrimes.c -pthread -O2 -o count -lm
//


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstdlib>
#include <math.h>
#include <pthread.h>
#include <iostream>
#include <vector>
#include <math.h>

#define MAX_NUMS 10000


using namespace std;

struct arg_struct {
	int a; // a = number of numbers to assess per thread
	int index; // index = index of vector nums to start at	
};

vector<unsigned long> nums;
int size = 0;
int count = 0;

/// primality test, if n is prime, return 1, else return 0
int isPrime(int64_t n)
{
     if( n <= 1) return 0; // small numbers are not primes
     if( n <= 3) return 1; // 2 and 3 are prime
     if( n % 2 == 0 || n % 3 == 0) return 0; // multiples of 2 and 3 are not primes
     int64_t i = 5;
     int64_t max = sqrt(n);
     while( i <= max) {
         if (n % i == 0 || n % (i+2) == 0) return 0;
         i += 6;
     }
     return 1;
}

void *countPrimes(void *arguments)
{
	struct arg_struct *args = (struct arg_struct *) arguments;
	cout << args -> a << " = nums (IN THREAD)" << endl;
	cout << args -> index << " = index (IN THREAD)" << endl;
	pthread_exit(NULL);
	return NULL;
}


int main(int argc, char *argv[])
{
       /// parse command line arguments
       int nThreads = 0;
       if(argc != 1 && argc != 2) {
           printf("Usage: countPrimes [nThreads]\n");
           exit(-1);
       }
       if( argc == 2) nThreads = atoi( argv[1]);

       /// handle invalid arguments
       if( nThreads < 1 || nThreads > 256) {
           printf("Bad arguments. 1 <= nThreads <= 256!\n");
       }
        if( nThreads == 1) {
            printf("I am not multithreaded yet :-(\n");
            exit(-1);
	}

	while(1)
	{
		unsigned long num;
		if(1 != scanf("%ld", & num)) break;
		else nums.push_back(num);
	}

	size = nums.size();
	if(size > MAX_NUMS)	
		{
		cout << "Error: Too many numbers in input file. " << endl;
		exit(-1);
		}

	int size_per_thread = size / nThreads;

	cout << nThreads << " = number of threads." << endl;
	cout << size << " = size of int vector " << endl;
	cout << size_per_thread << " = number of numbers each thread will analyze " << endl;

	vector<pthread_t> threads;

	// Create vector of structs
	vector<arg_struct> arg_vector;

	// Create the threads
	for(int i = 0; i < nThreads; i++)
	{
		arg_vector.push_back(arg_struct());
		arg_vector[i].a = size_per_thread;
		arg_vector[i].index = size_per_thread*i;
		cout << "CREATING THE STRUCT " << arg_vector[i].index << " = index " << arg_vector[i].a << " = num of nums " << endl; 
		pthread_t tid;
		threads.push_back(tid);
		if (pthread_create(&tid, NULL, &countPrimes, (void*)&arg_vector[i]) != 0)
		{
		cout << "Uh oh! " <<endl;
		return -1;
		}

	}

	// wait for all threads to finish
	for(int i = 0; i < threads.size(); i++)
	{
		pthread_join(threads[i], NULL);
	}
	

}

