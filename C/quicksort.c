#include <stdio.h>
#include <stdlib.h>


void quicksort(int *a , int start, int end);
int partition(int *arr, int start, int end);
void swap_var(int *a , int *b);

int arr[10] = {8,6,5,2,77,55,11,22,44,6};
int stopCMD = 0;
int main()
{
    quicksort(arr , 0, 9);
    for(int index = 0; index < 10; index++)
    {
        printf("%d  ", arr[index]);
    }
    puts("");
    return 0;
}

void quicksort(int *a , int start, int end)
{
    int p_index = 0;
    if(start < end )
    {
        p_index = partition(a, start, end);
        quicksort(arr , start, p_index -1);
        quicksort(arr , p_index +1, end);
    }
    return ;
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int part_index = start;
    for(int i = start; i <end; i++)
    {
        if(arr[i] <= pivot )
        {
            swap_var(&arr[i] , &arr[part_index]);
            part_index++;
        }       
    }
    swap_var(&arr[end] , &arr[part_index]);
    return part_index;
}

void swap_var(int *a , int *b)
{
    int temp = *a ^ *b;
    *a = *a ^ temp;

    *b = *b ^ temp;
}