#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main()
{
cout << "Hello World!" << endl;

fork();
fork();
fork();

cout << "Goodbye World!" <<endl;

return  0;

}
