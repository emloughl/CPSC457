// Using Break

#include <iostream>
using namespace std;

int main()
{
int n;

for(int i=1; i<=10; i++)
{
	cout << "In which year was the C++ language invented?";
	cin >> n;

	if (n == 1980)
	{
	cout << "Correct! " << endl;
	break;
	}
	else 
	cout << "Try again... "<< endl;

}


return(0);
}
