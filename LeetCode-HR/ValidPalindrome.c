#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool isPalindrome(char* s) {
    int len = strlen(s);
    char str1[len+1];
    char str2[len+1];
    memset(str1 , 0 , len+1);
    memset(str2 , 0 , len+1);
    int origin_index = 0;
    int copy_index = 0;
    int copy_index_str2 = 0;
    
    while(origin_index != len){
        if( (s[origin_index] >= 'a' && s[origin_index] <= 'z') || 
            (s[origin_index] >='0' && s[origin_index] <= '9') ){
            str1[copy_index++] = s[origin_index];
        }
        else if(s[origin_index] >= 'A' && s[origin_index] <= 'Z' ){
            str1[copy_index++] = s[origin_index] + 32;
        }
        origin_index++;
        
    }

    while(copy_index != copy_index_str2){
        str2[copy_index_str2++] = str1[copy_index - 1 -  copy_index_str2];
    }

    printf("%s\n%s\n" , str1 , str2);
    if(strcmp(str1 , str2) == 0)
        return true;
    return false;

}


int main(){
    const char* str1 = "race e         ca   r";

    if(isPalindrome(str1))
        printf("yes palindrome\n");
    else
        printf("Not palindrome\n");

    return 0;
}