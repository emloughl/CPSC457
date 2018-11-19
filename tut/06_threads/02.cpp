// Run BASH file from C++ Program

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
cout << "Hi!" << endl;
system("./a.sh");
cout << "BYE!"<<endl;
return 0;

}
