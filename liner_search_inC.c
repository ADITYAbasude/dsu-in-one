#include <stdio.h>

int main()
{
    int arr[100000], element = 99999;
    for (int i = 0; i < 100000; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < 100000; i++)
    {
        if (element == arr[i])
        {
            /* code */

            printf("%d ", arr[i]);
        }
    }

    return 0;
}