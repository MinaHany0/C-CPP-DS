#include <stdio.h>

int pow_manual(int m , int n);

int main(void)
{
    int num = 2;
    int power = 9;

    int result = pow_manual(2,9);
    printf("%d", result);

    return 0;
}

int pow_manual(int m , int n)
{
    int mult_at_end = 1;
    if(n == 0) return 1;

    if(n % 2 == 1)
    {
        mult_at_end = m;
    }
    while(n != 1)
    {
        m *= m;
        n /= 2;
    }
    return m * mult_at_end;
}