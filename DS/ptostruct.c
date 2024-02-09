#include <stdio.h>

int main(void)
{
    struct rectangle 
    {
        int width;
        int height;
    };

    struct rectangle rec = {10,5};
    struct rectangle* pToRec = &rec;

    printf("The width of my rectangle is %d", (*pToRec).width);

    return 0;
}