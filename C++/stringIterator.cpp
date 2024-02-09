#include <iostream>


int main()
{
    std::string str;
    getline(std::cin , str);

    std::string::iterator it = str.begin();

    int i = 0;
    for(; str[i] ; i++);
    
    
    std::cout << "the length of your string is " << i << std::endl;
}