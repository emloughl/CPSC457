// Create a phone book
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(){
    fstream phonefile("Contact.txt", ios::out);
    string number, name;

    cout << "Enter contact's info (0 for quit): " << endl;
    for(;;){
        cout << "\nNumber:";
        cin >> number;
        if(number == "0") break;
        cout << "Name: ";
        cin >> name;
        phonefile << number << " " << name << " " << endl;
    }
    cout << "All contacts stored in Contact.txt" << endl;
    return(0);
}
