// Using Class


#include <iostream>
#include <cstring>

using namespace std;

class Car
{
private:
	int speed = 30;

public:
	string name;

void speedUp(int n)
	{
	speed += n;
	cout << "Speed up to " << speed << endl;
	}	

int getSpeed()
	{
	return speed;
	}

};

int main()
{
	Car a;
	a.name = "Toyota";
	
	cout << "Current Speed: " << a.getSpeed() << endl;

	a.speedUp(10);
	cout << "Current Speed: " << a.getSpeed() << endl;

	return 0;

}
