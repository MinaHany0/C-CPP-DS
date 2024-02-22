#include <iostream>

class BasicCar
{
    public:
        virtual void maxSpeed(){std::cout << "Max speed is 50 " << std::endl;}
};
class AdvancedCar : public BasicCar
{
    public:
        void maxSpeed(){ std::cout << "Max speed is 100 " << std::endl;}
};

int main(){

    BasicCar *car = new AdvancedCar();  //base class pointer and derived class object
    car->maxSpeed();                    //max speed is of advanced car in case of virtual function
                                        //max speed is of basic car in case of no virtual
                                        //this is runtime polymorphism achieved by virtual , function overriding and inheritance

    delete car;
    return 0;
}