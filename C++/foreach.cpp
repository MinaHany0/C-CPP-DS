#include <iostream>

int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};

    for(auto &i : arr)
    {
        for(int j : i)
        {
            std::cout << j << " ";
        }
    }
}