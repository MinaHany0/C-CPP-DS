#include <stdio.h>


struct triangle
    {
        int base;
        int height;
};

void tri_init(struct triangle* tri , int b, int h);
int tri_area(struct triangle* tri);
void tri_changeBase(struct triangle* tri , int b);

int main(void)
{
    

    struct triangle t;
    tri_init(&t, 10 , 5);
    printf("the area of my triangle is %d\n", tri_area(&t));
    tri_changeBase(&t , 100);
    printf("the area of my triangle is %d\n", tri_area(&t));

    return 0;

}

void tri_init(struct triangle* tri , int b, int h)
{
    tri->base = b;
    tri->height = h;
    return;
}

int tri_area(struct triangle* tri)
{
    int area = 0.5 * (*tri).base * tri->height;

    return area;
}

void tri_changeBase(struct triangle* tri , int b)
{
    (*tri).base = b;
    return;
}