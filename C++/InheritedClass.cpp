#include <iostream>

class Rectangle
{
    public:
    int length;
    int width;
    Rectangle(int length = 1, int width = 1): length(length) , width(width) {}
    int getArea(void);
};

int Rectangle::getArea(void)
{
    return length * width;
}

class Parallelogram: public Rectangle
{
    int height;
    public:
    Parallelogram(int length = 1, int width = 2, int height = 1): Rectangle(){ this->height = height; }
    int getVolume(void){ return length * width * height ; }
};




int main()
{
    Rectangle rec;
    std::cout << "area of rectangle is " << rec.getArea() << std::endl;

    Parallelogram par;
    std::cout << "volume of parallelogram is " << par.getVolume() << std::endl;
    std::cout << "area of parallelogram is "   << par.getArea() << std::endl;

}