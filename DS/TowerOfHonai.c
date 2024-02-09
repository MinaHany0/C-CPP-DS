#include <stdio.h>

void TOH(int n, char A, char B, char C)
{
    if(n == 1){ printf("Move one disk from Tower %c to Tower %c\n", A, C); }
    else
    {
        TOH(n-1 , A, C, B);
        TOH(1   , A, B, C);
        TOH(n-1 , B, A, C);
    }
    return;
}

int main(void)
{
    TOH(4, 'A', 'B', 'C');
    return 0;
}