#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a,b) ( (a)>(b)? (a) : (b) )
int L_P_S(char* str);

int main()
{
    char* str = "abracecars";
    int lps = 0;
    lps = L_P_S(str);
    printf("length of longest palindrome subsequence is %d\n", lps);
    return 0;
}

int L_P_S(char* str)
{
    int i , j , d;
    int len = strlen(str);
    int** dp = (int**)calloc(len , sizeof(int*));
    for(int i = 0; i < len; i++)
    {
        dp[i] = (int*)calloc(len, sizeof(int));
        dp[i][i] = 1;
    }

    for(d = 2; d <= len; d++)
    {
        for(i = 0; i < len- d+1 ; i++)
        {
            j = i+d-1;
            if(str[i] == str[j] && 2 == d)
            {
                dp[i][j] = 2;
            }
            else if(str[i] == str[j])
            {
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else
            {
                dp[i][j] = MAX( (dp[i+1][j]) , (dp[i][j-1]) );
            }
        }
    }

    return dp[0][len - 1];
}