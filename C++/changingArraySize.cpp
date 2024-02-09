#include <iostream>

int main()
{

    int *ptr = new int[5];
    for(int i = 0; i < 5; i++)
        std::cin >> ptr[i];
    delete[] ptr;
    ptr = new int[6];
    std::cin >> ptr[5];
    for(int i = 0; i < 6; i++)
        std::cout << ptr[i] << " ";
    return 0;
}