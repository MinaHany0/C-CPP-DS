#include <stdio.h>
#include <string.h>


int main(void)
{
    char* str =" I love_Codeing very_much";

    char ch = '_';

    char* ptr = strchr(str, ch);

    printf("string after the character |%c| is |%s|\n", ch, ptr);

    char* ptr2 = strrchr(str, ch);

    printf("the string after the last |%c| is |%s|\n", ch , ptr2);

    return 0;
}