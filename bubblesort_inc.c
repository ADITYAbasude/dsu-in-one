#include <stdio.h>

void bubblesort(int *arr, int s)
{
    int ss = s, temp;
    for (int i = 0; i <= s - 1; i++)
    {
        for (int j = 0; j <= ss - 1; j++)
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
        printf("%d  ", arr[i]);
    }
}

int main()
{
    int arr[] = {2, 5, 4, 8, 6, 51, 12, 98, 0, 42, 50, 30, 70, 62, 15, 45, 65, 32, 23, 73, 70, 4, 465, 4, 48 , 496, 468 , 4, 654, 45, 4, 5, 45 ,4, 654, 655, 45, 4548, 48, 265, 854, 73, 894, 9874, 9832, 9829, 2, 98, 789, 79, 78, 78, 789, 7, 89, 97, 987, 987, 987, 89, 798, 29, 829, 82798, 4, 89, 984, 98, 7};
    int size = 100;
    bubblesort(arr, size);
    return 0;
}