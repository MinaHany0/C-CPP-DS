#include <iostream>
#include <stdio.h>

int main(void)
{
    struct rectangle 
    {
        int width;
        int height;
    };

    //rectangle *ptor = new rectangle;

    rectangle *ptor = (struct rectangle*)malloc(sizeof(struct rectangle));
    ptor->height = 15;
    ptor->width = 5;

    printf("the width of your rectangle is %d\n", ptor->width);
    printf("the height of your rectangle is %d\n", ptor->height);

    //delete ptor;
    free(ptor);
    return 0;
    
}