#include <stdio.h>
#include <string.h>


int main(void)
{
    char* str1 = "I love Code";
    int len = strlen(str1);
    char str2[len+1];
    str2[len] = "/0";

    strcpy(str2, str1);

    printf("%s", str2);
    return 0;
}