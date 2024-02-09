#include <iostream>

void swap(int &a, int &b);

int main(void)
{
    int a = 30;
    int b = 50;

    std::cout << "the value of a is " << a << std::endl;
    std::cout << "the value of b is " << b << std::endl;

    int &x = a, &y = b;

    swap(x,y);
    std::cout << "the value of a is " << a << std::endl;
    std::cout << "the value of b is " << b << std::endl;
    
    return 0;
}

//function to swap two variables
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}