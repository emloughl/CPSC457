// 10 - Print 10 Random Numbers

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

srand(time(NULL));
for(int i = 0; i<10; i++)
	{
	cout << rand()%10 + 1 << endl;
	}
}
