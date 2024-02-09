#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX(a,b) ( (a)>(b)? (a) : (b) )
char* L_P_S(char* str);

int main()
{
    char* str = "abracecars";
    int lps = 0;
    char* long_pal_substr = L_P_S(str);
    printf("Longest Palindrome Substring is %s\n", long_pal_substr);

    char* code = "daq6432:";
    char finalArray[50];
    memset(finalArray, '\0', 50);
    for(int i = 0; i < strlen(code); i++)
    {
        finalArray[i] = code[strlen(code) -1 -i];
    }
    char ffinalArray[50];
    memset(ffinalArray, '\0', 50);
    strncat_s(ffinalArray, 50, long_pal_substr, strlen(long_pal_substr));
    strncat_s(ffinalArray, 50, finalArray, strlen(finalArray));
    printf("Longest Palindrome Substring is %s\n", ffinalArray);
    
    return 0;
}

char* L_P_S(char* str)
{
    int i , j, d;
    int startPalindrome = -1, endPalindrome = -1;
    int currMax = 2;
    //char* retstr;

    int len = strlen(str);
    int**dp = (int**)calloc(len, sizeof(int*));
    for(int i = 0; i < len; i++)
    {
        dp[i] = (int*)calloc(len, sizeof(int));
        dp[i][i] = 1;
    }

    for(d = 2; d <= len; d++)
    {
        for(i = 1; i < len-d+1; i++)
        {
            j = i + d - 1;
            if(str[i] == str[j] && 2 == d)
            {
                dp[i][j] = 2 ;
            }
            else if(str[i] == str[j])
            {
                dp[i][j] = dp[i+1][j-1] + 2;
                if(dp[i][j] > currMax)
                {
                    currMax = dp[i][j];
                    startPalindrome = i;
                    endPalindrome = j;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    if(2 == currMax)
    {
        return "none";
    }
    else
    {
        char* result = (char*)calloc((endPalindrome - startPalindrome + 2) , sizeof(char));
        strncpy( result, str+startPalindrome, (endPalindrome - startPalindrome + 1) );
        result[(endPalindrome - startPalindrome + 1)] = '\0';
        
        return result;
    }
}