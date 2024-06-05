#include <stdio.h>  
#include <stdbool.h>

// SOLUTION 1
// bool isSubsequence(char* s, char* t) {
//     if(!s && !t) return true;
//     if(!s || !t) return false;

//     char *pFull = t;
//     char *pPart = s;

//     /* Notice that checking on ptr itself is wrong */
//     /* while(pFull && pPart) -> will not work because the pointer itself is always pointing to a place in memory */

//     while(*pFull && *pPart){
//         if(*pFull == *pPart){
//             pFull++;
//             pPart++;
//         }
//         else{
//             pFull++;
//         }
//     }
//     if(!*pPart)
//     {
//         return true;
//     }
//     return false;
// }

// SOLUTION 2
bool isSubsequence(char* s, char* t) 
{
    int s_len = 0, t_len = 0;
    /*IMPLEMENT USING RECURSION*/
}

int main()
{
    const char *string = "hello buddy";
    const char *part = "hlbdz";

    printf("%d\n" , isSubsequence( part ,string) );

    return 0;
}

