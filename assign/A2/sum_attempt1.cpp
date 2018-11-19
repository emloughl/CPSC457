
/* CPSC 457 - Operating Systems 
 * Evan Loughlin
 * UCID: 00503393
 * Date: Feb 8 2018
 * Assignment 2 - sum.cpp
 *
 * This program uses a multi-threaded solution for computing the 
 * sum of a large array of integers.
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <pthread.h>
#include <vector>
#include <fstream>

using namespace std;

unsigned long sum;

// Function for multi-threading, and summing parts of the array.
void *adder(void *threadarg)
{
	// Parse the thread arguments


	int this_sum = 0;
	for(int i = start_index; i <= end_index; i++)
	{
		sum += nums(i);
		this_sum += nums(i);

	}
	cout << "Thread " << pthread_self() << ": " << this_sum << endl;
}



int main(int argc, char ** argv)
{

string filename = argv[1];
int T = atoi(argv[2]);

// Open the file, and put it into an array:
ifstream in(filename);
int n;
vector<int> numbers;

while (in >> n) 
{
	numbers.push_back(n);
}

in.close();


// Create multiple threads:
pthread_t threads[T];
int i;

for (i = 0; i < (T-1); i++)
{
	// Create the message to pass to each thread.
	td[i].message = "This is message";

	pthread_create(&threads[i], NULL, adder, );

}

}
