#include <iostream>
#include <cstdarg>

int sum(int n , ...)
{
    va_list list;
    va_start(list , n);
    int a,b;
    int sum = 0;
    for(a = 0; a < n; a++)
    {
        b = va_arg(list , int);
        sum += b;
    }
    va_end(list);                   //you need to clean up the list or else end up with leaked memory
    return sum;
    
}

int mulltiply(int n , ...)
{
    va_list list;
    va_start (list , n);
    int x;
    int result =1;
    for(int i = 0; i < n; i++)
    {
        x = va_arg(list , int);
        result *= x;
    }
    va_end(list);                   //you need to clean up the list or else end up with leaked memory
    return result; 
}

int main(){
    int ss = sum(4,1,2,3,4);
    std::cout << ss << std::endl;

    int mm = mulltiply(5,1,2,3,4,5);

    std::cout << mm << std::endl;
}