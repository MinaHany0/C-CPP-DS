#include <iostream>
#include <string>

int add(int a , int b)
{
    if(a+b > 10)
        throw std::string{"overflow"};
        //throw "overflow";           //throwing this will find no catcher function and will display the following message
        //                              terminate called after throwing an instance of 'char const*'
        //                              solved by overloading catch function with one that recieve char const*
        //                              or do an All catch function
    return a+b;

}

int main()
{
    int a{} , b{};

    std::cout << "please enter first number" << std::endl;
    std::cin >> a;
    std::cin.ignore();
    std::cout << "please enter second number" << std::endl;
    std::cin >> b;
    std::cin.ignore();
    
    try{
        int c = add(a,b);

        std::cout << "the sum is " << c << std::endl;
    }
    catch(std::string e)
    {
        std::cout << "error " << e << std::endl;
    }
    catch(...)
    {
        std::cout << "Error 404" << std::endl;
    }

    std::cout << "END REACHED!";
}

