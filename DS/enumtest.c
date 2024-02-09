#include <stdio.h>

enum day 
    {
        a,b,c,d,e
    };

void returnDay(enum day r);

int main(void)
{
    

    enum day saturday = b;
    returnDay(saturday);

}

void returnDay(enum day r)
{
    if(r == b)
    {
        printf("saturday");
    }
    else{
        printf("friday");
    }
    return;
}