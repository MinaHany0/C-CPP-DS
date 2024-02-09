#include <stdio.h>
#include <string.h>


int main(void)
{
    char* str1 = "mina hany";
    char* str2 = "mina hanx";

    int cmpResult = strncmp(str1, str2, 5);

    printf("%d", cmpResult);
    return 0;
}