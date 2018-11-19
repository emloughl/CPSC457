// Append to a text file

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
 ofstream file("simple.txt", ios::app);

 string newStr = "I am new line.\n";
 file << newStr;

 cout << "Text appended. " << endl;

 return(0);


}
