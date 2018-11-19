// Create a new text file

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
string str="This is a simple text. \n This is line 1 \n and this is line 2.";

ofstream myfile("simple.txt");

myfile<<str;

return(0);

}
