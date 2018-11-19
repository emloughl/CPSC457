// Read input arguments from command line

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char ** argv)
{
// Handle command line arguments
	if (argc != 3) 
	{
	 cerr << "Usage <suffix> <number of files>" << endl;
	 exit(-1);
	}

string filetype = argv[1];
int number = stoi(argv[2]);

cout << filetype << " " << number << endl;

return 0;


}
