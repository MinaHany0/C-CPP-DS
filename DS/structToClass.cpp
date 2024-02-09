#include <iostream>
#include <stdio.h>

class rectangle
{
    public:
    int length;
    int width;

    
    rectangle(int l , int w)
    {
        length = l; width = w;
    }
    int area(void)
    {
        return length * width;
    }

    int perimeter(void)
    {
        return 2*(length + width);
    }

    void re_init(int l , int w)
    {
        length = l; width = w;
    }
};

int main(void)
{
    rectangle r(10,5);

    int r_area = r.area();
    int r_perimeter = r.perimeter();

    std::cout << "for rectangle \nLength is " << r.length << " and width is " << r.width<<std::endl;
    std::cout << "area is " << r_area<<std::endl << "perimter is " << r_perimeter << std::endl;

    r.re_init(5,5);

    std::cout << "for rectangle \nLength is " << r.length << " and width is " << r.width<<std::endl;
    std::cout << "area is " << r.area()<<std::endl << "perimter is " << r.perimeter() << std::endl;


    return 0;
}