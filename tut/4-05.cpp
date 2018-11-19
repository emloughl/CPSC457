#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main()
{
cout << "Hello" << endl;
pid_t pid;
pid = fork();

if(pid<0)
	cout << "Fork Failed!"<<endl;

else if (pid == 0)
{
	cout << endl<< "I am Child "<< endl;
	for (char i = 'a'; i<='z'; i++) 
		cout << i << endl;
	cout << endl;

}
else
{
	cout << endl<< "I am Parent" << endl;
	for (int i = 1; i<=70; i++)
		cout << i << endl;
	cout << endl;
}

cout << "Good Bye" << endl;
return 0;

}
