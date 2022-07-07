#include <stdio.h>
#include <conio.h>



typedef struct imaginaryNum
{
	unsigned int realNum;
	int imagNum;
	
}imaginaryNum;



int seqSearch (imaginaryNum* arr, int size, imaginaryNum data);




int main (int argc, char** argv)
{
	imaginaryNum key;
    imaginaryNum arr[10];
	
	int i;
	
	for (i = 0; i<10; i++)
	{
		arr[i].realNum = (i+1);
		arr[i].imagNum = (10-i);
	}


	 clrscr();
	 printf("\n______________________sequential search on array complex numbers ______________");
	 
	 printf("\n\n please insert real part of a complex number: ");
	 scanf("%d", &key.realNum);
	 
	 printf("\n please insert imaginary part of a complex number: ");
	 scanf("%d", &key.imagNum);
	 
	 printf("%d", seqSearch ( arr, 10, key));
     getch();

	 return 0;
	 
}


int seqSearch (imaginaryNum* arr, int size, imaginaryNum data)
{
    int index;

    for (index =0; index <size ; index++)
    {
        if ( (arr[index].realNum == data.realNum) && (arr[index].imagNum == data.imagNum) )
        {
            printf(" \nfound at position: ");
            return index+1;
        }
    }

    printf(" \nNot found ");
    return -1;
}