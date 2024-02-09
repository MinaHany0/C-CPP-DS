#include <iostream>

class Data
{
    public:
    unsigned int number1 =0;        //this is a member or a parameter
    unsigned int number2;           //this is a member or a parameter
    void fun();                     //this is a member function

    //void Data(){}                 //gives error because constructor caanot have return type
    Data() = default;                         //this is the default constructor used to init members when you create an object
    Data(unsigned int number3);     //this is the parameter constructor
    //Data(Data &_data);              //this is the explicit calling copy instructor
};

//Data::Data(){ std::cout << "Default Constructor has been called\n";}
Data::Data(unsigned int number3)
{
    this->number2 = number3;
    std::cout << "Parameter Constructor member function has been called" << std::endl;
}
//Data::Data(Data &_data)               //explicitly copy constructor
//{   
//    std::cout << "Copy Constructor member function has been called" << std::endl;
//    number1 = _data.number1;
//    number2 = _data.number2;    
//}

int main()
{   
    Data d1(3);

    std::cout << "value of Data object d1 number 1 and number 2 is ";
    std::cout << d1.number1 << " & " << d1.number2 << std::endl;
    std::cout << "************************************************************\n";

    Data d2;
    std::cout << "value of Data object d2 number 1 and number 2 is ";
    std::cout << d2.number1 << " & " << d2.number2 << std::endl;
    std::cout << "************************************************************\n";

    Data d3(d1); //when no explicit copy constructor is available the compiler implicitly declares it
    std::cout << "value of Data object d2 number 1 and number 2 is ";
    std::cout << d3.number1 << " & " << d3.number2 << std::endl;
    std::cout << "************************************************************\n";

}