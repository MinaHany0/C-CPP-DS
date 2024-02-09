#include <stdio.h>


class triangle
{
    private:
        int base;
        int height;
    public:
        triangle(int b, int h)
        {
            base = b;
            height = h;
            return;
        }

        int tri_area(void)
        {
            int area = 0.5 * base * height;

            return area;
        }

        void tri_changeBase(int b)
        {
            base = b;
            return;
        }
};

int main(void)
{
    

    class triangle t(20,15);
    printf("the area of my triangle is %d\n", t.tri_area());
    t.tri_changeBase(200);
    printf("the area of my triangle is %d\n", t.tri_area());

    return 0;

}

