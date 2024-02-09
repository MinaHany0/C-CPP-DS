#include <iostream>

template<class T>
class arithmetic
{
    private:    
        T a;
        T b;
    public:
        arithmetic(T a, T b);
        T add(void);
        T sub(void);
};

template<class T>
arithmetic<T>::arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template<class T>
T arithmetic<T>::add(void)
{
    T sum = a+b;
    return sum;
}

template<class T>
T arithmetic<T>::sub(void)
{
    T subtract = a - b;
    return subtract;
}

int main(void)
{

    arithmetic<int> ar_int(5,10);
    arithmetic<float> ar_float(2.3 , 1.2);

    std::cout << "the sum of integer numbers is " << ar_int.add() << std::endl;
    std::cout << "the subtraction of float numbers is " << ar_float.sub() << std::endl;
    return 0;
}