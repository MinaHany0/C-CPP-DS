#include <stdio.h>
#include <string.h>


int main(void)
{
    char str1[15] = "I love Code\n";
    printf("%s", str1);
    char* str2 = "GVery Much";

    strncat_s(str1, 15,str2,1);

    printf("%s", str1);
    printf("%d", strlen(str1));
    return 0;
}