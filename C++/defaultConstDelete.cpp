#include <iostream>

class Data{
    
    int number;
    int flag;
    public:
    Data() = delete;
    Data(int n, int f ): number(n) , flag(f) {}

    ~Data();

    void printData(void);
};

Data::~Data(){
    std::cout << "Object Data is ebign deleted"<<std::endl;
}

void Data::printData(void){
    std::cout << "your variables are " << number << " " << flag << std::endl;
}
int main()
{
    Data data(10, 20);

    //Data error;                 //gives an error because default constructor is deleted
    data.printData();
    return 0;
}