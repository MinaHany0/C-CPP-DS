#include <iostream>

class car{
    public:
        virtual void start(void) = 0;
        virtual void stop(void) = 0;

        virtual ~car();                 //abstract class needs a virtual destructor
};

class Innova: public car{
    public:
        void start(void){ std::cout <<"Innova Started" << std::endl;}
        void stop(void) { std::cout << "Innova Stopped" << std::endl;}
};

class Corolla: public car{
    public:
        void start(void) { std::cout << "Corolla Started"<<std::endl;}
        void stop(void) { std::cout << "Corolla Stopped" << std::endl;}
};


int main()
{
    car *MinaCar = new Corolla();
    car *AndrewCar = new Innova();

    MinaCar->start();
    MinaCar->stop();
    AndrewCar->start();
    AndrewCar->stop();

    delete MinaCar;
    delete AndrewCar;
    return 0;

}