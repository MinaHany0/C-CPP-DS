#include <iostream>



int main(void)
{
    int *ptr = new int;
    *ptr = 65;

    char *q = reinterpret_cast<char*>(ptr);

    std::cout << *ptr << std::endl;
    std::cout << *q << std::endl;

    return 0;


}