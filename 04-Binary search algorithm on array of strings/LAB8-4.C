#include <stdio.h>
#include <conio.h>
#include <string.h>

int binSearch (char** arr, int size, char* data);


int main (int argc, char** argv)
{
	char* name;
	char arr[5][8] = {"ahmed", "amr", "mahmoud","mostafa" ,"omar"};
	

	 clrscr();
	 printf("\n______________________Binary search on array of strings LAB______________");
	 
	 printf("\n\n please insert data name: ");
	 scanf("%s", name);

	 printf("%d", binSearch(arr, 5, name));
	 getch();

	 return 0;

}


int binSearch (char** arr, int size, char* data)
{

	int high, mid, low =0;
	high = size-1;


	while (high >= low)
	{
		mid = (high+low)/2;

		if (strcmpi(arr[mid], data) == 0 )
		{
			printf(" found at position: ");
			return mid+1;
		}
		else if (strcmpi(arr[mid], data) < 0)
		{
			low = mid+1;
		}
		else if (strcmpi(arr[mid], data) > 0)
		{
			high = mid-1;
		}
	}

	printf(" Not found ");
	return -1;
}