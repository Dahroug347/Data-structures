
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

typedef struct stack
{
    struct data* start;
    struct data* end;
}stack;

data* createNode (void);
void push (stack *myStack, data* d);
int getData (stack* Mylist);
int pop (stack* Mylist);

int main (void)
{
   stack myStack;
   int i, terminate = 0;
   data* n;
   data* temp;
   int dataElement = 0;
   int option, dataInsert;
   int getVal;
   clrscr();
   printf("\n____________________________ stack linked list lab ______________________");

   myStack.start = myStack.end = NULL;

   temp = myStack.start;
   printf("\n this is my stack: ");
   while (temp != NULL)
   {
	   printf("%d ", temp->value);
	   temp = temp->next;
   }



   while(!terminate)
   {
	   printf("\n\n please select one option from below: \n1- push into stack.\n2- get from stack.\n3- pop from stack.\n4- exit\n\n>> ");
	   scanf("%d",&option);
	   switch (option)
	   {
			case 1:
				clrscr();
				push (&myStack, n);
			break;

			case 2:
				clrscr();
				getVal = getData(&myStack);
				if (getVal == 0)
				{
					printf(" stack is empty !!");
				}
				else
				printf(" the data at top of stack is: %d", getVal);
			break;

			case 3:
				clrscr();
				getVal = pop(&myStack);
				 if (getVal == 0)
				{
					printf(" stack is empty !!");
				}
				else
				printf(" the data at top of stack was: %d", getVal);


			break;

			case 4:

			terminate = 1;
			break;
	   }

	   printf("\n\n\n\n updated list: ");
	   temp = myStack.start;
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

void push (stack* myStack, data* NNode)
{
	NNode = createNode();

    printf("\n\n please push value: ");
    scanf("%d", &NNode->value);

	if (myStack->start == NULL)
		myStack->start = myStack->end = NNode;
	else
	{
		NNode->prev = myStack->end;
		myStack->end->next = NNode;
		myStack->end = NNode;
	}
}

int getData (stack* Mylist)

{
	data* get;
	get = Mylist->end;

   if (get == NULL)
		return 0;

  else
    return get->value;
}

int pop (stack* MyList)
{
    int val;
	data* temp;
    temp = MyList -> end;

	if (temp== NULL)
		return 0;
    else
    {
        val = temp->value;
        MyList->end = MyList->end->prev;
		MyList->end->next = NULL;
		free(temp);
		return val;
    }
}
