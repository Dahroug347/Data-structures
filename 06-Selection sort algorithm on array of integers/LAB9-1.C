#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SIZE 10

void swap (int* pTr1, int* pTr2)
{
    int temp = *pTr1;
    *pTr1 = *pTr2;
    *pTr2 = temp;
}

void selectionSort(int* arr, int size)
{
    int index, position, indexHolder = 0;

    for (position = 0; position <size; position++)
    {
        for (index = position+1; index<size; index++)
        {
            if (arr[index] < arr[indexHolder])
                indexHolder = index;
        }
        swap(&arr[position], &arr[indexHolder]);
        indexHolder = position+1;
    }

    for (position = 0; position<size; position++)
    {
        printf(" %d", arr[position]);
    }
}

int main()
{
    int dataArr[SIZE];
    int index, dataElement;

    clrscr();
    printf("\n ------------- selection sort lab -------------");
    printf("\n\n\tPlease insert your array elements data: ");
    for (index = 0; index <SIZE; index++)
    {
        scanf("%d", &dataArr[index]);
    }
    printf("\n=============================================================================");
    printf("\n\tSelection sort result -> ");
    selectionSort(dataArr,SIZE);

    getch();
    return 0;
}
