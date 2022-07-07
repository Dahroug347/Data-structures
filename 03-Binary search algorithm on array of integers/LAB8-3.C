#include <stdio.h>
#include <conio.h>


int binSearch (int* arr, int size, int data);




int main (int argc, char** argv)
{
	int key, result;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};


	 clrscr();
	 printf("\n______________________Binary search on array of integers LAB______________");
	 
	 printf("\n\n please insert data key: ");
	 scanf("%d", &key);
	 
	 printf("%d", binSearch(arr, 10, key));
     getch();

	 return 0;
	 
}


int binSearch (int* arr, int size, int data)
{

    int high, mid, low =0;
    high = size-1;


	while (high >= low)
	{
		mid = (high+low)/2;

        if (arr[mid] == data)
        {
            printf(" found at position: ");
            return mid+1;
        }
        else if (arr[mid] < data)
        {
            low = mid+1;
        }
        else if (arr[mid] > data)
        {
            high = mid-1;
        }
    }

    printf(" Not found ");
    return -1;
}