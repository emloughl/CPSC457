// Multiprocess Programming
// CPSC 457

#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main()
{
   cout << "Process ID id : " << getpid() << endl;
   cout << "Parent Process ID is " << getppid << endl;
   return 0;
}


