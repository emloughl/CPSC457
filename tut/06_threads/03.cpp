/*
 For assignment:
 For your second question - the C++ program must behave exactly like the bash script. 
 That means it must accept parameters from the command line.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
cout << "Hi!" << endl;

//system("./a.sh");
system("find $(pwd) -name \"*.txt\" -printf \'%s %p\n\'| sort -nr | head -3");

cout << "BYE!" << endl;
return 0;

}
