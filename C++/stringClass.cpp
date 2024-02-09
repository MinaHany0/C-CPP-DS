#include <iostream>
#include <string>

using namespace std;
int main()
{
    std::string s1 {"Hello"};
    std::string s2 {" world"};
    
    
    s1 += s2;
    cout << s1 << endl;
    cout << s1.at(6) << endl;

    cout << s1.front() << endl;
    cout << s1.back() << endl;
    return 0;
}