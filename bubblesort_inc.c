#include <stdio.h>

void bubblesort(int *arr, int s)
{
    int ss = s, temp;
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < ss-1; j++)
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
    for (int i = 0; i < s; i++)
    {
        printf("%d  " , arr[i]);
    }
}

int main()
{
    int arr[] = {2, 5, 4, 8, 6 , 51 , 12 , 98 , 0 , 42 , 50 , 30 , 70 , 62 , 15 , 45, 65 , 32, 23, 73}, size = 20;
    bubblesort(arr, size);
    return 0;
}