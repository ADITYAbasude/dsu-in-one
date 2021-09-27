#include <stdio.h>

void delection(int arr[5] , int index , int s ){
    for (int i = index; i < s-1; i++)
    {
        arr[i] = arr[i+1];

    }
    
    for (int i = 0; i < s-1; i++)
    {
        printf("%d\n" , arr[i]);
    }
    
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}, index = 2 , s = 5;
    delection(arr, index , s);
    return 0;
}