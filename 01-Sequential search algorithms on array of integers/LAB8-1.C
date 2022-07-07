#include <stdio.h>
#include <conio.h>


int seqSearch (int* arr, int size, int data);




int main (int argc, char** argv)
{
	int key, result;
    int arr[10] = {6, 2, 3, 4, 10, 1, 7, 8, 9, 5};


	 clrscr();
	 printf("\n______________________sequential search on array of integers LAB______________");
	 
	 printf("\n\n please insert data key: ");
	 scanf("%d", &key);
	 
	 printf("%d", seqSearch(arr, 10, key));
     getch();

	 return 0;
	 
}


int seqSearch (int* arr, int size, int data)
{
    int index;

    for (index =0; index <size ; index++)
    {
        if (arr[index] == data)
        {
            printf(" \nfound at position: ");
            return index+1;
        }
    }

    printf(" \nNot found ");
    return -1;
}