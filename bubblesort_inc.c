#include <stdio.h>

void bubblesort(int *arr, int s)
{
    int ss = s, temp;
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < ss - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        ss--;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int main()
{
    int arr[5] = {999, 75865, 854, 57, 4};
    int size = 5;
    bubblesort(arr, size);
    return 0;
}