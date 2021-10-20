#include <stdio.h>

void selectionsort(int *arr, int size)
{
    int temp, s = size  , min;
    for (int i = 0; i <= size - 1; i++)
    {
        min=i;
        for (int j = i + 1; j < size; j++)
        {

            if (arr[min] > arr[j])
            {
                min=j;
            }
        }
        

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main()
{
    int arr[] = {4, 1, 2, 10}, size = sizeof(arr) / sizeof(arr[0]);

    display(arr, size);
    selectionsort(arr, size);
    display(arr, size);
    return 0;
}