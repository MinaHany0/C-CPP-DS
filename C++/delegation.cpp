#include <iostream>

class Data
{
    public:
    int num1;
    bool flag;

    Data();
    Data(bool flag);
    Data(bool flag, int number);
};

Data::Data()
{
    std::cout << "this is your default constructor\n";
}
Data::Data(bool flag):Data() 
{
    this->flag = flag;
    std::cout << "this is your first parametrized constructor\n";
}
Data::Data(bool flag, int number):Data(flag)
{
    this->num1 = number;
    std::cout << "this is your second parametrized constructor\n";
}


int main(void)
{
    Data d(true , 10);
}