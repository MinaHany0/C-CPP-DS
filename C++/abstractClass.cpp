#include <iostream>

class Base1{                        //this is an apure virtual class == ABSTRACT Class
    public:
        virtual void fun1() = 0;    //you cannot make an object of this class
        virtual void fun2() = 0;    //you can only make a pointer to it
                                    //its main goal is to achieve polymorphism
};

class Base2{
    public:
        virtual void fun1() = 0; //pure virtual function        //this is a class that has virtual and concrete functions
        void fun2()                                             //Also called an abstract class and you cannot make an instance of it
            {std::cout << "Hello from Base2" <<std::endl ;}     //its goal is reusability in child class and virtual function
                                                                //to be overridden in child class to achieve polymorphism
                                                                //remember pure virtual functions make class non objectable                 
};

class Base3{
    public:
        virtual void fun1()                                     //this is a class that has concrete functions
            {std::cout << "Hello from Base3" <<std::endl ;}     //
        void fun2()                                             //this is NOT called an abstract class
            {std::cout << "Hello from Base3" <<std::endl ;}     //its goal is reusability in child class
};

class derived : public Base3{
    public:
        void fun1(){ std::cout << "Hello from derived Class" << std::endl; }
        void fun2(){ std::cout << "Hello from derived Class" << std::endl; }
};


int main()
{

}