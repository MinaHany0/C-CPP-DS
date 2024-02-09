#include <iostream>
using namespace std;
int main()
{
    char name[50];

    cout << "please enter your name ";
    cin.get(name , 50);
    cin.ignore();
    cout << "welcome " << name;

    cout << "please enter your name";
    cin.getline(name , 50);
    
    cout << "welcome " << name;

}