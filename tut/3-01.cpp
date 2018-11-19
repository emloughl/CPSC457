// 01 - Using Buffer

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
int count=0;

fstream myfile("romeo-and-juliet.txt", ios::in);
char buffer[1000000];
myfile.read(buffer, 1000000);

for(int i = 0; i < 1000000; i++)
	if(buffer[i] == '\n')
		count++;

cout << count << endl;

return 0; 


}
