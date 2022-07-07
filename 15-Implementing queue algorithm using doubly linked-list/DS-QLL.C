
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    struct data* prev;
    struct data* next;
    int value;
}data;

typedef struct queue
{
    struct data* start;
    struct data* end;
}queue;

data* createNode (void);
void input(queue *myQueue, data* d);
int getData (queue* Mylist);
int output (queue* Mylist);

int main (void)
{
   queue myQueue;
   int i, terminate = 0;
   data* n;
   data* temp;
   int dataElement = 0;
   int option, dataInsert;
   int getVal;
   clrscr();
   printf("\n____________________________ queue linked list lab ______________________");

   myQueue.start = myQueue.end = NULL;

   temp = myQueue.start;
   printf("\n this is my queue: ");
   while (temp != NULL)
   {
	   printf("%d ", temp->value);
	   temp = temp->next;
   }



   while(!terminate)
   {
	   printf("\n\n please select one option from below: \n1- input into queue.\n2- get from queue.\n3- output from queue.\n4- exit\n\n>> ");
	   scanf("%d",&option);
	   switch (option)
	   {
			case 1:
				clrscr();
				input(&myQueue, n);
			break;

			case 2:
				clrscr();
				getVal = getData(&myQueue);
				if (getVal == 0)
				{
					printf(" queue is empty !!");
				}
				else
				printf(" the data at top of queue is: %d", getVal);
			break;

			case 3:
				clrscr();
				getVal = output(&myQueue);
				 if (getVal == 0)
				{
					printf(" queue is empty !!");
				}
				else
				printf(" the data at top of queue was: %d", getVal);


			break;

			case 4:

			terminate = 1;
			break;
	   }

	   printf("\n\n\n\n updated list: ");
	   temp = myQueue.start;
	   while (temp != NULL)
	   {
		   printf("%d ", temp->value);
		   temp = temp->next;
	   }

	   getch();
	   clrscr();

   }

   getch();

   return 0;
}


data* createNode (void)
{
	data* NewNode;
	NewNode = (data*)malloc(sizeof(data));
	if (NewNode == NULL)
		return NULL;
	else
	{
		NewNode->prev = NewNode->next = NULL;
		return NewNode;
	}
}

void input(queue* myQueue, data* NNode)
{
	NNode = createNode();

    printf("\n\n please input value: ");
    scanf("%d", &NNode->value);

	if (myQueue->start == NULL)
		myQueue->start = myQueue->end = NNode;
	else
	{
		NNode->prev = myQueue->end;
		myQueue->end->next = NNode;
		myQueue->end = NNode;
	}
}

int getData (queue* Mylist)

{
	data* get;
	get = Mylist->start;

   if (get == NULL)
		return 0;

  else
    return get->value;
}

int output (queue* MyList)
{
    int val;
	data* temp;
    temp = MyList -> start;

	if (temp== NULL)
		return 0;
    else
    {
        val = temp->value;
        MyList->start = MyList->start->next;
		MyList->start->prev = NULL;
		free(temp);
		return val;
    }
}
