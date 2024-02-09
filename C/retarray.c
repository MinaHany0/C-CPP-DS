#include <stdio.h>
#include <stdlib.h>

typedef struct
    {
        char anme[15];
        int id;
        float age;
    }student;

int main() 
{
    student *ptos = NULL;
    ptos = (student*)malloc(sizeof(student));
    ptos->id = 1234;

    printf("%d", ptos->id);
    return 0;


}
