#include <iostream>

class Data
{
    int id = 15;
    const int c_id = 30;

    public:
        void print_variable(void) { std::cout << "hello from normal method, Variable is " << id << std::endl; }
        void print_variable(void)const { std::cout << "hello from const method, Variable is " << c_id << std::endl;} 
};

int main()
{   
    Data d_normal;
    const Data d_const;
    d_normal.print_variable();
    d_const.print_variable();
    return 0;

}