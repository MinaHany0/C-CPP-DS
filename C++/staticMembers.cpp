#include <iostream>

class room
{
    
    public:
    const static double f;
    static int area;
    static const int perimeter;
        void getArea(void)
            {std::cout <<"area is "<<area;}
        void getPeri(void)
            {std::cout <<"Peri is "<<area;}
};

const double room::f = 15.5898f;
int room::area = 5;
const int room::perimeter = 15;

int main()
{
    room r1;
    r1.getArea();
    r1.getPeri();
    std::cout << std::endl << (&r1.area);
    
    std::cout << std::endl << (&r1.perimeter);
    std::cout << std::endl << (r1.f);
}