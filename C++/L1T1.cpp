#include <iostream>
#include <array>
#include <string>
#include <bitset>


long long returnBinary(int a);
int returnInteger(long long a);

int main(void)
{
    int userNumber = 0;
    long long binaryNumber = 0;
    int decimalNumber = 0;
    std::bitset<4>b = 0;

    b= 8;
    std::cout << b << std::endl;
    b.set();
    std::cout << b << std::endl;
    b.reset();
    std::cout << b << std::endl;

    //std::cout << "Enter a binary number: \n";
    //std::cin >>userNumber;
    //decimalNumber = returnInteger(userNumber);
    //std::cout << decimalNumber << std::endl;
}

long long returnBinary(int a)
{
    std::array<bool,100>binary;
    int counter = 0;
    long long binaryNumber = 0;

    while(a != 0)
    {
        binary[counter] = a % 2;
        counter++;
        a /= 2;
    }

    for(int i = 0; i < counter; i++)
    {
        std::cout << binary[counter-1-i];
        binaryNumber *= 10;
        binaryNumber += binary[counter -1 -i];
        
    }
    return binaryNumber;
}

int returnInteger(long long a)
{
    int result= 0;
    int adder = 1;
    int temp = 0;
    while(a != 0)
    {
        temp = a & 1;
        a /=10;
        if(1 == temp)
        {
            result +=adder;
        }
        adder *=2;
    }
    return result;
}