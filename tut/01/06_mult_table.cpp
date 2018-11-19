// A Program That Display 5*10 Multiplication Table

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, j;
	for(i=1; i<=5; i++)
	{
		for(j=1; j<=10; j++)
		cout << setw(4) << i*j;
		cout << endl;
	}

return(0);

}
