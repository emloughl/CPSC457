#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main()
{
	fork();
	for(int i = 1; i <= 50; i++)
		cout << i << endl;

	return 0;

}
