#include <iostream>

int binarySearching(int arr[], int len, int key)
{
    int LHS = 0, RHS = len-1;
    int mid;

    while(LHS <= RHS)
    {
        mid = (RHS + LHS) / 2;
        if(key == arr[mid]){ return mid; }
        else if(key < arr[mid]) { RHS = mid -1; }
        else {LHS = mid + 1; }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,55,66,77,88,99,445,1025,6574,9999};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key;
    std::cout << "please enter the key ";
    std::cin >> key;

    int idx = binarySearching(arr, len, key);
    if(-1 == idx) {std::cout << "Element not Found !" << std::endl;}
    else { std::cout << "Element found at index " << idx << std::endl;}
    return 0;
}