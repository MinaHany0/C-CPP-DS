#include <stdio.h>
#include <string.h>

int main()
{
    char *str1 = "Yamete kudusai onii chan";
    char str2[] = " ";

    char *str3 = strtok(str1 , str2);
    while(str3)
    {
        puts(str3);
        str3 = strtok(NULL , str2);
    }

    for(int i = 0; i < 25; i++)
    {
        if(str1[i] == '\0') printf("\\0\n");
        else printf("%c\n" , str1[i]);
    }
}