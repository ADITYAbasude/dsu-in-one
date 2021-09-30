#include <stdio.h>

void selectionsort(int *arr, int size)
{
    int temp, s = size , small;
    for (int i = 0; i < size - 1; i++)
    {
        small = i;
        for (int j = i+1; j < s ; j++)
        {
            if (arr[j] < arr[small])
            {
                temp = arr[small];
                arr[small] = arr[i];
                arr[i] = temp;
            }
        }

    }
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int main()
{
    int arr[3] = {4, 1, 2}, size = 3;
    selectionsort(arr, size);
    return 0;
}