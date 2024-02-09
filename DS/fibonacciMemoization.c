#include <stdio.h>
#include <stdlib.h>


int dp[100]= {0};

int fibonacci(int n)
{   
    if(n <= 1)
    {
        dp[n] = n;
        return dp[n];
    }
    if(dp[n-2] == -1) { dp[n-2] = fibonacci(n-2); }
    if(dp[n-1] == -1) { dp[n-1] = fibonacci(n-1); }
    dp[n] = dp[n-1] + dp[n-2];
    return dp[n];
}


int main(void)
{
    int num = 15;

    for(int i = 0; i < 100; i++) {dp[i] = -1;}

    int fnum = fibonacci(num);

    printf("fibonacci of number %d is %d\n", num , fnum);

    return 0;
    
}