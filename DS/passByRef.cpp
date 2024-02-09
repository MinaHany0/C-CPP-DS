#include <iostream>

//this is call by reference not call by address
//notice that call by reference functions are copied and pasted inside the main function
//they should not be used with bug functions and not to be used extensively
//notice the only difference between call by value and call by ref is in the argument / formal parameter format/syntax
void swap( int &x,int  &y)
{
    int temp = x;
    x = y;
    y = temp;

}
int main(void)
{
    int a = 5;
    int b = 10;
    std::cout << "the value of a variable is " << a << std::endl;
    std::cout << "the value of b variable is " << b << std::endl;

    swap( a, b);
    std::cout << "the value of a variable is " << a << std::endl;
    std::cout << "the value of b variable is " << b << std::endl;
}