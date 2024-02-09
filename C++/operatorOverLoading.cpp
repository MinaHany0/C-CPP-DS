#include <iostream>

class complex
{
    private:
        int real;
        double img;
    public:
        complex(int r = 0, double i = 0){real = r; img = i;}
        complex(const complex &c){ real = c.real; img = c.img; }
        complex operator+(const complex &c);
        friend complex operator- (const complex &c1 , const complex &c2);
        friend std::ostream& operator<<( std::ostream &o , complex &c);
        friend std::istream& operator>>( std::istream &i , complex &c);
};

complex complex::operator+ (const complex &c)
{
    complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
}

complex operator- (const complex &c1 , const complex &c2)
{
    complex t;
    t.real = c1.real - c2.real;
    t.img  = c1.img  - c2.img ;
    return t;
}

std::ostream& operator<< (std::ostream &o , complex &c)
{   
    
    o << c.real << " + " << c.img << "i" << std::endl;
    return o;
}

std::istream& operator>> (std::istream &i , complex &c)
{
    i >> c.real >> c.img;
    return i;
}

int main()
{
    complex c1{1,5};
    complex c2{5,7.5};

    complex c3 = c1+c2;
    std::cout << c3;

    complex c4 = c2 - c1;
    std::cout << c4 << c3 << c2;

    complex c5;
    std::cin >> c5;
    std::cout << c5;

}