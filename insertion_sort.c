#include <stdio.h>
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
void insertionSorting(int *arr, int size)
{
    for (int i = 1; i <= size - 1; i++)
    {
        int j, key;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main()
{
    int arr[] = {1, 5, 3, 4, 8, 45 ,12 , 100 , 2 , 85 }, size = 10;
    display(arr, size);
    insertionSorting(arr, size);
    display(arr, size);
    return 0;
}