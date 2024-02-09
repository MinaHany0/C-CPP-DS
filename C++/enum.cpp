#include <iostream>
#include <algorithm>

enum traffic{ RED, GREEN, YELLOW };
std::string fun1( traffic key)
{
    #define MYCase(X) \
        case X:       \
            return std::string(#X)
    switch(key)
    {
        MYCase(RED);
        MYCase(GREEN);
        MYCase(YELLOW);
    }
    #undef MYCase
    return "";
}

int main(void)
{
    

    std::cout << fun1(RED);
    return 0;
}