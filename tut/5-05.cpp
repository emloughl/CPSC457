// Using wait() (Written in C++)
//

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	int status;
	pid_t pid;

	if (fork())
	{
		cout << "I am Parent and Want to Wait" << endl;
		pid = wait(&status);
		for(int i=1; i<=4; i++)
			cout << i << endl;

		cout << "Child ID is: " << pid << endl;
	}
	else
	{
		cout << "I am child. My ID is: " << getpid() << endl;
		for(char i = 'a'; i <= 'f'; i++)
			cout<<i<<endl;
	}
		
	cout << "GoodBye"<<endl;


return 0;
}

