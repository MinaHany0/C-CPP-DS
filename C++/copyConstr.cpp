#include <iostream>

class Data{
public:
    int *ptr = nullptr;
    explicit Data(int *_ptr){
        ptr = _ptr;
    }
    ~Data(){
        delete ptr;
        ptr = nullptr;
    }
};

int main(){

    Data d1( Data(new int(5)));

    Data d2(d1);
    *(d1.ptr) = 1000;

    std::cout << "data in d1 is " << (*d1.ptr) << std::endl;
    std::cout << "data in d2 is " << (*d2.ptr) << std::endl;
    return 0;
}