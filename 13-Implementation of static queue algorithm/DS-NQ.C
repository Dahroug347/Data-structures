#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



typedef struct que
{
    int size, boq;
    int *qu;
}que;

int initQueue (que* q, int s)
{
    q->size = s;
    q->boq= 0;
    q->qu = (int*)malloc (s*sizeof(int));
    if (q->qu != NULL)
        return 1;
    else
        return  0;
}

int fullQueue (que q)
{
    if (q.boq == q.size )
        return 1;
    else
        return 0;
}


int emptyQueue (que q)
{
    return (q.boq == 0);
}

int input (que* q, int data)
{
    if (fullQueue(*q))
        return 0;
    q->qu[q->boq]= data;
    q->boq ++;
    return 1;
}

int output (que* q, int* data)
{
    int i;
    if (emptyQueue(*q))
        return 0;

    *data = q->qu[0];
    for (i = 0; i<q->boq; i++)
    {
        q->qu[i] = q->qu[i+1];
    }
    q->boq --;
    return 1;
}

int main()
{
   que myQueue;
   int i;
   int p;

    clrscr();

    printf("\n________________implementation of static queue________________");

    initQueue( &myQueue, 10);
     printf("\n inputing process: \n\n");

    for (i = 0; i<myQueue.size; i++)
    {
        input(&myQueue, (i*2));
		printf("  %d", myQueue.qu[myQueue.boq-1]);
	}

	printf("\n\n outputting process: \n\n");

	for (i = 0; i<myQueue.size; i++)
	{
		output(&myQueue, &p);
		printf("  %d", p );
    }

    getch();
    return 0;
}
