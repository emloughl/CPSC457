// 09 - Call by Reference
#include <iostream>

using namespace std;

void swap(float &x, float &y)
{
	float temp = x;
	x = y;
	y = temp;
}

int main()
{
	float a = 55.5, b = 88.8;
	cout << "a= " << a << " , b = " << b << endl;
	swap(a,b);
		cout << "a= " << a << " , b = " << b << endl;
	return(0);
}
