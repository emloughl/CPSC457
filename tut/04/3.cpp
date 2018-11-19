#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main()
{
	pid_t pid;
	cout << "Hello World" << endl;

	pid = fork();
	pid = fork();
	pid = fork();

	cout << "Bye " << pid << endl;

	return 0;
}
