#include <stdio.h>

int partition(int *arr, int l, int h)
{
    int pivot = arr[l], i = l + 1, j = h, temp;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void quickshorting(int *arr, int l, int h)
{
    int index;
    if (l < h)
    {
        index = partition(arr, l, h);
        quickshorting(arr, l, index - 1);
        quickshorting(arr, index  +1, h);
    }
}

void display(int *arr , int s){
    for (int i = 0; i < s; i++)
    {
        printf("%d\t" , arr[i]);
    }
    printf("\n");
    
}

int main()
{
    int arr[6] = {546, 58, 41532, 45, 20, 7}, size = 6;
    display(arr , size);
    quickshorting(arr, 0, size-1);
    display(arr , size);

    return 0;
}