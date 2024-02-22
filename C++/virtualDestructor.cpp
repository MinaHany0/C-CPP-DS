#include <iostream>

class Base{
    public:
    virtual ~Base( ){std::cout << "Destructor of base class" << std::endl;}
    //virtual is needed to call the destructor of derived class when using base class pointer to derived class object
    //notice this behaviour is not replicated in normal object calling or destroying
};
class derived: public Base {
    public:
    ~derived() { std::cout << "Destructor of derived class " << std::endl;}
};

int main(){
    derived d;

    Base *p = new derived;

    delete p;
    return 0;
}