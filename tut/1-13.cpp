// Using Structure

#include <iostream>
using namespace std;

struct Person
{
 char name[50];
 int age;
 float salary;
};

int main()
{
 Person p1;
 cout << "Enter full name: ";
 cin.get(p1.name, 50);

 cout << "Enter age: ";
 cin >> p1.age;

 cout << "Enter salary: ";
 cin >> p1.salary;

 cout << "\n Displaying Information:" << endl;
 cout << "Name: " << p1.name << endl;
 cout << "Age: " << p1.age << endl;
 cout << "Salary: " << p1.salary << endl;

 return(0);

}
