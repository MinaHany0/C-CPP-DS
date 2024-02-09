#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (((a) >= (b))? (a): (b))

int longstCommonSubsequence(char* str1, char* str2);
int main(void)
{
    char* str1 = "AGGTAB";
    char* str2 = "GXTXAYB";
    int lCS = longstCommonSubsequence(str1, str2);
    printf("longest common subsequence is %d", lCS);
    return 0;
}


int longstCommonSubsequence(char* str1, char* str2)
{
    int len_1 = strlen(str1);
    int len_2 = strlen(str2);

    int **dp = (int**)calloc(len_1+1 , sizeof(int*));
    for(int i = 0; i < len_1+1; i++)
    {
        dp[i] = (int*)calloc(len_2+1 , sizeof(int));
    }

    for( int i = 0; i < len_1; i++)
    {
        for(int j = 0; j < len_2; j++)
        {
            if(str1[i] == str2[j])
            {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else
            {
                dp[i+1][j+1] = MAX((dp[i+1][j]),(dp[i][j+1]));
            }
        }
    }

    int result = dp[len_1][len_2];
    free(dp);
    return result;
}