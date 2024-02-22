#include <iostream>


int main()
{
    int a, b, c;
    std::cout << "please enter 3 variables "<< std::endl;
    std::cin >> a;
    std::cin.ignore();
    std::cin >> b;
    std::cin.ignore();
    std::cin >> c;
    std::cin.ignore();

    try
    {
        if(a == 0) throw 101;
        c = b/a;
        std::cout << "the value of c is " << c << std::endl;
    }
    catch(int e)
    {
        std::cout << "Division by zero, Error Code is " << e << std::endl;
    }
    
    
}