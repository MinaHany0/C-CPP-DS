#include <stdio.h>
#include <stdlib.h>

struct array{
    int *ptr;
    int size;
    int length;
};

void arrayFill(struct array *_arr)
{
    puts("Please enter no of desired elements to fill: ");
    scanf("%d",&_arr->length);
    if(_arr->length > _arr->length)
    {
        puts("Invalid input .. exiting now ...");
        scanf("%d", &_arr->size);
        exit(1);
    }
    for(int i = 0; i < _arr->length; i++)
    {
        printf("Please enter element no %d : ", i);
        scanf("%d", &_arr->ptr[i]); fflush(stdin);
    }
}

void arrayDisplay(struct array *_arr)
{
    for(int i = 0; i < _arr->length; i++)
        printf("%d\t", _arr->ptr[i]);
    puts("");
    
}

int main()
{
    struct array arr1  = { NULL, 0 ,0};
    puts("Please enter size of desired array: ");
    scanf("%d", &arr1.size);  fflush(stdin);
    arr1.ptr = (int*)malloc(arr1.size * sizeof(int));

    arrayFill(&arr1);
    arrayDisplay(&arr1);
    

}