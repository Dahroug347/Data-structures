#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SIZE 5
#define STR  10

void swap (char** pTr1, char** pTr2)
{
    char ** temp = *pTr1;
    *pTr1 = *pTr2;
    *pTr2 = temp;
}

void selectionSort(char** arr, int size)
{
    int index, position, indexHolder = 0;

    for (position = 0; position <size; position++)
    {
        for (index = position+1; index<size; index++)
        {
            if (strcmpi(arr[index], arr[indexHolder])  < 0 )
                indexHolder = index;
        }
        swap(&arr[position], &arr[indexHolder]);
        indexHolder = position+1;
    }

    for (position = 0; position<size; position++)
    {
        printf("  %s", arr[position]);
    }
}

int main()
{
    char*dataArr[SIZE] = {"amr", "omar", "mahmoud", "ali", "ahmed"};

    clrscr();
    printf("\n ------------- selection sort lab for strings -------------");
    printf("\n\n\tSelection sort result -> ");
    selectionSort(dataArr,SIZE);

    getch();
    return 0;
}
