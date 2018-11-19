// Loop by While

#include <iostream>
using namespace std;

int main()
{
int n, c=0;
cout << "Enter a number: ";
cin >> n;
while (n>0)
{
n = n/10;
c++;
}
cout<<"\nThis number has " << c << " digits." << endl;
return(0);
}
