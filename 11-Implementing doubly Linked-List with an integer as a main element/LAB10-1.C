
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    struct Node* prev;
    struct Node* next;
    int data;
}Node;

typedef struct List
{
    struct Node* start;
    struct Node* end;
}List;

Node* createNode (void);
void appendNode (List* MyList, Node* NNode);
Node* searchNode (List* Mylist, int key);
int deleteNode (List* MyList, int key);
void insertNode (List* MyList, Node* NNode);
void freeList (List* ll, Node* node);


int main (void)
{
   List Mylist;
   int i, terminate = 0;
   Node* n;
   Node* temp;
   int dataElement = 0;
   int option, dataInsert;
   clrscr();
   printf("\n____________________________ linked list lab ______________________");

   Mylist.start = Mylist.end = NULL;

   for (i = 0; i<5; i++)
   {
	   n = createNode();
	   n-> data = dataElement;
	   appendNode(&Mylist, n);
	   dataElement += 2;
   }

   temp = Mylist.start;
   printf("\n this is my list: ");
   while (temp != NULL)
   {
	   printf("%d ", temp->data);
	   temp = temp->next;
   }



   while(!terminate)
   {
	   printf("\n\n please select one option from below: \n1- create node.\n2- append node.\n3- search node.\n4- delete node.\n5- insert node.\n6- free list and exit\n\n>> ");
	   scanf("%d",&option);
	   switch (option)
	   {
			case 1:
				n = createNode();
				clrscr();
				printf("\n\n please put node's value with respect to list order: ");
				scanf("%d", &dataInsert);
				n->data = dataInsert;
			break;

			case 2:
				if (n == NULL)
				{
					clrscr();
					printf("\n\n there is no enough space !");
					terminate = 1;
				}

				else
					appendNode(&Mylist, n);
			break;

			case 3:
				clrscr();
				printf("\nplease insert data u need to find: ");
				scanf("%d", &dataInsert);
				temp = searchNode (&Mylist,dataInsert);
				if (temp == NULL)
				printf("\nNot found");

				else
				{
					 printf("found at position: %d", temp -> data);
					 temp -> data = dataInsert;
				}

			break;

			case 4:
				clrscr();
				printf("\nplease insert data u need to delete: ");
				scanf("%d", &dataInsert);
				if (deleteNode (&Mylist, dataInsert) == 0)
				printf("\nthis element already doesn't exist");
			break;

			case 5:
				clrscr();
				insertNode (&Mylist, n);
			break;

			case 6:
				freeList(&Mylist, n);
				terminate = 1;
			break;
	   }

	   printf("\n\n\n\n updated list: ");
	   temp = Mylist.start;
	   while (temp != NULL)
	   {
		   printf("%d ", temp->data);
		   temp = temp->next;
	   }

	   getch();
	   clrscr();

   }

   getch();

   return 0;
}


Node* createNode (void)
{
	Node* NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
		return NULL;
	else
	{
		NewNode->prev = NewNode->next = NULL;
		return NewNode;
	}
}

void appendNode (List* MyList, Node* NNode)
{
	if (MyList->start == NULL)
		MyList->start = MyList->end = NNode;
	else
	{
		NNode->prev = MyList->end;
		MyList->end->next = NNode;
		MyList->end = NNode;
	}
}

Node* searchNode (List* Mylist, int key)
{
	Node* get;
	int i = 0;
	get = Mylist->start;

   if (get == NULL)
		return NULL;

  else
  {
	   while ( (get!= NULL) && (get->data != key))
   {
	   get = get->next;
	   i++;
   }
	get -> data = (i+1);
	return get;
  }

  return NULL;

}

int deleteNode (List* MyList, int key)
{
	Node* temp;

	if (MyList->start==NULL)
		return 0;

	temp = searchNode (MyList, key);

	if (temp == MyList->start && temp == MyList->end)
	{
	  MyList->start = MyList->end = NULL;
	  free(temp);
	}

	else if (temp == MyList->start)
	{
		MyList->start = MyList->start->next;
		MyList->start->prev = NULL;
		free(temp);
	}

	else if (temp == MyList->end)
	{
		MyList->end = MyList->end->prev;
		MyList->end->next = NULL;
		free(temp);
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}

	return 1;
}

void insertNode (List* MyList, Node* NNode)
{
    Node* temp = MyList->start;

    while ( (temp != NULL) && (temp->data < NNode->data) )
        temp = temp->next;

    if (temp == NULL)
        appendNode (MyList, NNode);

    else if (temp == MyList->start)
    {
        MyList->start->prev = NNode;
        NNode->next = MyList->start;
        MyList->start = NNode;

    }
    else
    {
        temp->prev->next = NNode;
        NNode->prev  = temp->prev;
        temp->prev = NNode;
        NNode->next = temp;
    }

}

void freeList (List* ll, Node* node)
{
    Node* temp;
    node = ll->start;
    while (node != NULL)
    {
        temp = ll->start;
        node = node->next;
        ll->start = node;
        free(temp);
    }
}
