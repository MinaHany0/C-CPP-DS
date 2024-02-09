#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a>b)? (a) : (b))

int longIncSubseq(int arr[],int len);
int main(void)
{
    int arr[] = {10,22,9,33,21,50,41,60};
    int len = sizeof(arr) / sizeof(arr[0]);
    int LIS = longIncSubseq(arr,len);
    printf("The Longest Increasing Subsequence is %d numbers", LIS);
    return 0;
}

int longIncSubseq(int arr[],int len)
{
    int *lis = (int*)calloc(len , sizeof(int));
    for(int i =0; i < len; i++)
    {
        lis[i] = 1;
    }

    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                int prevLisPlusOne = lis[j] + 1;
                lis[i] = MAX(lis[i] , prevLisPlusOne);
            }
        }
    }
    
    int highestLis = 1;
    for(int i = 0; i < len; i++)
    {
        highestLis = MAX(highestLis , lis[i]);
    }
    free(lis);
    return highestLis;
}