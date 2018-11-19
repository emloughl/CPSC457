#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main()
{
	cout << "Hello" << endl;
	pid_t pid;
	pid = fork();

	if (pid < 0)
		cout << "Fork failed.";

	else if (pid ==0)
	{
		cout << endl << " I am Child " << endl;
		for (char i = 'a'; i <= 'g'; i++) // Change loop to A to z
			cout << i << endl;
		cout << endl;
	}

	else
	{
		cout << endl << "I am Parent" << endl;
		for (int i = 1; i <= 4; i++)
			cout << i << endl;
		cout << endl;
	}

	cout << "Good Bye" << endl;

return 0;
}
