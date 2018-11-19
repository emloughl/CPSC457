// 11 - Polymorphism

#include <iostream>

using namespace std;

int sum (int a, int b)
{
	return(a+b);
}

int sum (int a, int b, int c)
{
return (a+b+c);
}

double sum(double a, double b)
{
return(a+b);
}


int main()
{
cout << " 12 + 16 = " << sum(12,16) << endl;
cout << " 12 + 16 + 10 = " << sum(12,16,10) << endl;
cout << "10.5 + 14.4 = " << sum(10.5,14.4) << endl;
return (0);
}
