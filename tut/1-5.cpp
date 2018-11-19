// Fibonacci using For

#include <iostream>
using namespace std;

int main()
{
int f1=0, f2=1, f3, i;
cout << "Fibonacci: " << f1 << ", " << f2;

for (i = 1; i <= 8; i++)
{
f3 = f1 + f2;
while(f3<1000)
	{
	cout << ", " << f3;
	f1=f2;
	f2=f3;
	f3=f1+f2;
	}
cout << endl;

return (0);

}

}
