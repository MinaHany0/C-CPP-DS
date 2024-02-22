#include <iostream>

class trace{
    std::string str;
    public:
    trace(std::string str): str(str){std::cout  << "entering function " << str << std::endl;}
    ~trace()                {std::cout          << "exiting function  " << str << std::endl;}
};

void fun1(void)
{
    trace t(__func__);
}
void fun2(void)
{
    trace t(__func__);
    fun1();
}

int main(void){
    trace t(__func__);
    fun2();
    return 0;
}
