// Using Fork and PID()
//

#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main()
{
pid_t pid;
cout << "Hello world!" << endl;

pid = fork();

if (pid > 0)
	cout << "I'm the Parent and the PID of my child is "<< pid<<endl;
else
	cout << "I'm the child, because my pid return value is " << pid << endl;

cout <<"Goodbye World!"<<endl;

return 0;



}
