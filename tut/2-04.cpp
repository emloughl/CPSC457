// Read Only a Text File

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
fstream myfile("simple.txt", ios::in);

if(!myfile)
{
	cout << "Error in opening the file" << endl;
	exit(1);

}


string str;
while(getline(myfile, str))
	cout << str << endl;

return(0);

}
