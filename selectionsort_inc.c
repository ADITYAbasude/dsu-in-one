#include <stdio.h>

void selectionsort(int *arr, int size)
{
    int temp, s = size;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < s - 1; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        s--;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int main()
{
    int arr[] = {4, 1, 2, 7, 6 , 10 ,8}, size = 7;
    selectionsort(arr, size);
    return 0;
}