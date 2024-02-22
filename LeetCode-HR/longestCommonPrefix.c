#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int counter = 0;
    int flag = 0;
    for(int i = 0;; i++)
    {
        char comparison = strs[0][i];
        for(int j = 0; j < strsSize; j++)
        {
            if(strs[j][i] == '\0' || comparison != strs[j][i]) 
            {
                flag = 1;
                break;
            }
        }

        if(flag) 
            break;
        else 
            counter++;
    }

    char *result = (char*)calloc(counter+1 , sizeof(char));
    memcpy(result , strs[0], counter);
    return result;
}

int main()
{
    int strsSize = 3;
    char** strs = (char**)calloc(strsSize , sizeof(char*));
    strs[0] = (char*)calloc(10, sizeof(char));
    strs[1] = (char*)calloc(10, sizeof(char));
    strs[2] = (char*)calloc(10, sizeof(char));
    memcpy(strs[0], "reflower", sizeof("reflower"));
    memcpy(strs[1], "flow", sizeof("flow"));
    memcpy(strs[2], "flight", sizeof("flight"));

    char* stringResult = longestCommonPrefix(strs, strsSize);
    printf("result is : %s", stringResult);

    free(stringResult);
    for(int i = 0; i < strsSize; i++)   
        free(strs[i]);
    free(strs);
    return 0;
}