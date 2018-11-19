// Search a name
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(){
    fstream phonefile("Contact.txt", ios::in);
    string number, name, searchname;
    bool isfound = false;

    cout << "Enter contact's number for search:" << endl;
    cin >> searchname;

    while(phonefile >> number){
        phonefile >> name;
        if(searchname == name){
            cout << name << " " << number << endl;
            isfound = true;
        }
    }
    if(!isfound) cout << searchname << " is not in this contact file." << endl;
    return(0);
}
