#include <iostream>

class parent
{
    public:
        void display(){std::cout << "this is parent class " << std::endl;}
};
class child : public parent
{
    public:
        void display(){ std::cout << "this is child class " << std::endl;}
};

int main(){

    parent par;
    child chi;

    par.display();
    chi.display();
    return 0;
}