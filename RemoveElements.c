#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
    int a = 0;
    int t = numsSize;
    while (t >= 0)
    {
        for (int i = 0; i < numsSize - 1; i++)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[i + 1];
                nums[i + 1] = val;
            }
        }

        t -= 1;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            a++;
        }
        else
        {
            break;
        }
    }

    return a;
}
int main()
{
    int arr[] = {3, 2, 2, 3};
    int size = sizeof(arr) / sizeof(int);
    int val = 2;
    int k = removeElement(arr, size, val);
    printf("%d", k);
    return 0;
}
