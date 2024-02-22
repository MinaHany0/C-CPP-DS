#include <iostream>

class Parent{
    public:
    virtual void show (void) final
    {
        std::cout << "this is the Parent class" << std::endl;
    }
};
class Child: public Parent
{
    public:                                                     
    //void show (void)                                                      //remember a final finction cannot be overridden
    //{
    //    std::cout << " this is the Child class" << std::endl;
    //}
};
int main(){
    double y = 3.3;
    int x = 55;

    auto z = y * x;

    decltype(z) a = z / 55;

    std::cout << "Z is " << z << " while a is " << a << std::endl;

Child child;
child.show();
return 0;

}