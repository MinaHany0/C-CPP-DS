#include <stdio.h>
#include <string.h>


int main(void)
{
    char* str1 = "I love Code";
    int len = strlen(str1);
    char str2[20];
    

    strncpy(str2, str1, len+1);
    str2[len-2] = '\0';

    printf("%s", str2);
    return 0;
}
