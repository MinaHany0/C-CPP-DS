#include <stdio.h> 

#define PASTER(X) printf("token + "#X "= %d" , token ## X)

int main(void)
{

    int token8 = 88;
    PASTER(8);

    return 0;
}