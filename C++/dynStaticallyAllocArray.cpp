#include <iostream>
using namespace std;

int main()
{
    int size;
    std::cin >> size;                                                                       //User enters size
    cout << "address of size var in stack is " << &size << endl;;                           //0x26761ff89c

    int A[size];                                                                            //array with dynamic size decided by the user
    cout << "address of array a with dyn size is" << &A << endl;                            //0x26761ff880
    
    for(int i = 0; i < size; i++)
        cin >> A[i];
    cout << "address of first element in array a with dyn size  is" << &A[0] << endl;       //0x26761ff880

    int array[] = {1,2};                                                                    //normal array with static size
    cout << "address of array array is" << &array << endl;                                  //0x26761ff894

    int *dynarr { new int[size]{0}};                                                        //dyanmically allocated arary with new keyword
    cout << "address of array with new keyword is" << dynarr << endl;                       //0x185398f3b00

    return 0;
}