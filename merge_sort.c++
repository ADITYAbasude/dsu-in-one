// #include<iostream>

// using namespace std;

// void display(int *arr ,int size){
//     for(int i = 0; i < size; i++){
//         cout << arr[i] << "\t";
//     }
// }

// //conquering the array
// void merge(int arr[] , int start , int mid , int last){
//     int n1 = mid - start + 1 ;
//     int n2 = last - mid;

//     // temp array to copy the data
//     int leftArr[n1];
//     int rightArr[n2];

// //coping data into temp array
//     for(int i = 0; i < n1; i++){
//         leftArr[i] = arr[start + i];
//     }
//     for(int i = 0; i < n2; i++){
//         rightArr[i] = arr[mid + 1 + i];
//     }

//     int i = 0 , j = 0 , k = start;
    
//     //sorting data
//     while(i < n1 && j < n2){
//         if(leftArr[i] <= rightArr[j]){
//             arr[k] = leftArr[i];
//             i++;
//         }else{
//             arr[k] = rightArr[j];
//             j++;
//         }
//         k++;
//     }
//     while(i < n1){
//         arr[k] = leftArr[i];
//         i++;
//         k++;
//     }
//     while(j < n2){
//         arr[k] = rightArr[j];
//         j++;
//         k++;
//     }
// }

// //dividing the array into the parts
// void mergeSort(int arr[] , int start , int last){
//     if(start < last){
//         int mid = (start + last) / 2;
//         mergeSort(arr , start , mid);
//         mergeSort(arr , mid +1  , last);
//         merge(arr , start , mid , last);
//     }
// }


// //main function
// int main(){
//     int arr[] = {8,4,5,6,1};
//     int size = (sizeof(arr) / sizeof(int));

//     cout << "Given array is: ";
//     display(arr , size);
//     mergeSort(arr , 0 , size-1);
//     cout << "\nSorted array is: ";
//     display(arr, size);
//     return 0;
// }



#include <stdio.h>

int main()
{
    int arr[10] = {00, 10, 20, 30, 40, 50, 60, 70, 80, 90}, num, min, max, mid;
    printf("Enter a number : ");
    scanf("%d", &num);
    min = 0;ṇ
    max = 9;

    while (min <= max)
    {
        mid = (min + max) / 2;

        if (num == arr[mid])
        {
            printf("%d ", arr[mid]);
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

    if (arr[mid] != num)
    {
        printf("Not found ");
    }
    return 0;
}