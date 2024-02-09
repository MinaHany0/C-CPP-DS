#include <stdio.h>

int fun(int num);

int main(void)
{
    int n = 5;
    int result = fun(5);

    printf("result is %d\n", result);

    return 0;
}

int fun(int num)
{
    static int x = 5;
    int result = 0;
    if(num > 0)
    {
        x +=5;
        result = fun(num-1) + x;
    }
    return result;
}
