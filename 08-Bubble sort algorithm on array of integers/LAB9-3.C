#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SIZE    5

void swap (int* pTr1, int* pTr2)
{
    int * temp = *pTr1;
    *pTr1 = *pTr2;
    *pTr2 = temp;
}

void bubbleSort (int* arr, int size)
{
    int i;
	int j = 1;
    int sorted = 0;

    while (!sorted)
    {
        sorted = 1 ;

		for (i = 0 ; i < (size-j); i++)
        {
            if (arr[i] > arr [i+1])
            {
                swap (&arr[i], &arr[i+1]);
                sorted = 0;
            }

        }

        j++;
    }

    for (i = 0; i <size; i++)
    {
        printf ("%d ", arr[i] );
    }

}

int main()
{
    int dataArr[SIZE] = {2,1,5,0,7};

    clrscr();
    printf("\n ------------- bubble sort lab -------------");
    printf("\n\n\tbubble sort result -> ");
    bubbleSort(dataArr,SIZE);

    getch();
    return 0;
}
