#include <iostream>
#include <bitset>

int main()
{
    int x= 10;
    std::cout << "please Enter a Number: ";
    std::cin >> x;
    std::cout << std::bitset<16>(x) << std::endl;
    std::cout << " & x value is " << x << std::endl;
}