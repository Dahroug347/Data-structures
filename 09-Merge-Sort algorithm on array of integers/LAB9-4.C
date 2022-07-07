#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SIZE    9

void merge (int *arr1 , int size1, int *arr2, int size2, int *mergeArr)
{
    int i= 0, j = 0, k = 0;

    while (i < size1 && j <size2)
    {
        if (arr1[i] < arr2[j])
           mergeArr[k++] = arr1[i++];
        else
           mergeArr[k++] = arr2[j++];
    }

    while (i < size1)
        mergeArr[k++] = arr1[i++];

    while (j < size2)
        mergeArr[k++] = arr2[j++];
}

void  mergeSort (int* arr, int size)
{
    int* rightArr;
    int* leftArr;
    int rightSize, leftSize;
    int i;

    if (size < 2)
        return;


    leftSize = size/2;
    rightSize =  (size - leftSize);

    leftArr = (int*)malloc(leftSize * sizeof(int));
    rightArr = (int*)malloc(rightSize * sizeof(int));


    for (i = 0; i<leftSize; i++)
        leftArr[i] = arr[i];

    for (i = leftSize; i<size; i++)
        rightArr[i-leftSize] = arr[i];

     mergeSort (leftArr, leftSize);
     mergeSort  (rightArr, rightSize);

     merge (leftArr, leftSize, rightArr, rightSize, arr);

    free(leftArr);
    free(rightArr);

}

int main()
{
    int dataArr[SIZE] = {2,1,5,0,7,10,9,8,3};
    int i;
    clrscr();
    printf("\n ------------- merge sort lab -------------");
    printf("\n\n\merge sort result -> ");
    mergeSort(dataArr,SIZE);

    for (i = 0; i<SIZE; i++)
        printf("%d ", dataArr[i]);

    getch();
    return 0;
}
