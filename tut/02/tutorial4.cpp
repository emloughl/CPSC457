// Read Only a text file
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
    fstream myfile("simple.txt", ios::in);
    int count = 1;

    if(!myfile){
        cout << "Error in opening the file" << endl;
        exit(1);
    }

    string str;
    while(getline(myfile, str)) cout << str << ", line count is: " << count++ << endl;

    return(0);
}
