// Loop by While
//

#include <iostream>
using namespace std;

int main()
{
int n, c=0;
cout << "Enter a Number: ";
cin >> n;

while(n>0)
	{
	n = n/10;
	c++;
	}

cout << "This number has " << c << " digits."<< endl;
return(0);
}
