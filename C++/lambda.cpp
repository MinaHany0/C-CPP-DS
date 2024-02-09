#include <iostream>


int main()
{
    int a = 5;
    int b = 6;
    int c = 7;

    auto fn = [](auto x , auto y){return x+y;};

    auto var = fn(3.5,3.6);
    std::cout << "fn value is " << var <<std::endl;
    var = fn(3,3);
    std::cout << "fn value is " << var <<std::endl;



    return 0;

}