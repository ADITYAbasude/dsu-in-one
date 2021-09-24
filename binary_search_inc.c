#include <stdio.h>

int main()
{
    int arr[10] = {00, 10, 20, 30, 40, 50, 60, 70, 80, 90}, num, min, max, mid;
    printf("Enter a number : ");
    scanf("%d", &num);
    min = 0;
    max = 9;

    while (min <= max)
    {
        mid = (min + max) / 2;

        if (num == arr[mid])
        {
            printf("%d ", arr[mid] );
            break;
        }
        else if (num > arr[mid])
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }

    if(arr[mid] != num){
        printf("Not found ");
    }
    return 0;
}