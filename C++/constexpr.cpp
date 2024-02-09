#include <iostream>

constexpr int summation(int a , int b)
{
    int result = 0;
    //std::cin >> result;               //if you put any runtime operation, produces error
    for(int i = 0; i < b; i++)
    {
        result += a;
    }
    return result;
}

int main()
{
    constexpr int n1 = 5+2;

    constexpr int sum = summation(5,4);
    std::cout << sum;
}