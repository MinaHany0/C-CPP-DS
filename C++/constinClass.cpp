#include <iostream>

//class data
//{
//    public:
//    const int var;
//    bool flag = 5;
//    data() = delete;
//    data(int num);
//};
//
//
//data::data(int num):var(num)
//{
//    std::cout << "this is your paramterized cosntructor";
//}

class data
{
    public:
    const int var;
    int num;

    //data() = default;           //this says the explicitly declared default constructor will be deleted because
                                //because the default constructor cannot init the const variable
    data(int number);

    void printconst(int variable) const 
    {
        //num = variable;           //you cannot change a variable in const method , but you can read it normally
        std::cout << num<< std::endl;
    }
};

data::data(int number):num(number), var(number)
{
    std::cout << "hi";
}

int main()
{
    data d(5);
    d.printconst(15);
    return 0;
}