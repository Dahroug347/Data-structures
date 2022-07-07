#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/* console display */
#define   NORMAL_TEXT       0x0F
#define   HIGHLIGHTED_TEXT  0xF0

/* menu items */
#define   NEW                   0
#define   DISPLAY               1
#define   SEARCH                2
#define   DELETE                3
#define   INSERT                4
#define   SORT                  5
#define   EXIT                  6

/**** key Values ****/

/* extended keys*/
#define   UP_ARROW              72
#define   DOWN_ARROW            80
#define   HOME                  71
#define   END                   79
/* normal keys*/
#define   ENTER                 13
#define   ESCAPE                27

typedef struct emp
{

	float salary;
	float bonus;
	float deduction;
	float netSalary;
	int age;
	unsigned int id;
	char aName[10];
}emp;

typedef struct Employee
{
    struct Employee* pPrevEmp;
    emp Emp;
    struct Employee* pNextEmp;
}Employee;

typedef struct DataBase
{
    struct Employee* pFirstEmp;
    struct Employee* pLastEmp;
}DataBase;

DataBase MyData;
int key;
int x,y;
int numOfEmp = 0;
int flag;

Employee* pCreateNewEmp(void)
{
    Employee* NewEmp = (Employee*)malloc(sizeof(Employee));

    if (NewEmp == NULL)
    {
        numOfEmp --;
        return NULL;
    }

    else
    {
        int row = 2, col;
        NewEmp->pPrevEmp = NewEmp->pNextEmp = NULL;

        printf("\n you can add a new employee %d here: ", numOfEmp);
		 col = 6;
		 gotoxy(row,col);
		 printf("name: ");

		 gotoxy(row,col+2);
		 printf ("age: ");

		 gotoxy(row,col+4);
		 printf ("ID: ");


		 gotoxy(row+20,col);
		 printf ("salary: ");

		 gotoxy(row+20,col+2);
		 printf ("deduction: ");

		 gotoxy(row+20,col+4);
		 printf ("bonus: ");


		 gotoxy(row+6,col);
		 flushall();
		 gets(NewEmp->Emp.aName);

		 gotoxy(row+6,col+2);;
		 flushall();
		 scanf("%d",&NewEmp->Emp.age);

		 gotoxy(row+6,col+4);
		 flushall();
		 scanf("%u",&NewEmp->Emp.id);

		 gotoxy(row+32,col);
		 flushall();
		 scanf("%f",&NewEmp->Emp.salary);

		 gotoxy(row+32,col+2);
		 flushall();
		 scanf("%f",&NewEmp->Emp.deduction);

		 gotoxy(row+32,col+4);
		 flushall();
		 scanf("%f",&NewEmp->Emp.bonus);

        return NewEmp;
    }
}

void appendEmployee (DataBase* db, Employee* e)
{
    if (db->pFirstEmp == NULL && db->pLastEmp == NULL)
        db->pFirstEmp = db->pLastEmp = e;
    else
    {
        e->pPrevEmp = db->pLastEmp;
        db->pLastEmp->pNextEmp = e;
        db->pLastEmp = e;
    }
}

void newEmp (Employee* newEm)
{
    newEm = pCreateNewEmp ();

    if (newEm == NULL)
        printf("\n sorry there isnt enough space allocated");
    else
    appendEmployee (&MyData, newEm);

	key = getch();
}

void displayEmp (void)

{
    Employee* node;

    if (MyData.pFirstEmp == NULL)
        printf("\n there is no any employees saved in database");

    else
    {
         node = MyData.pFirstEmp;
          x = 2;
          y = 4;
         while (node != NULL)
         {
             gotoxy(x,y);
             printf("employee name: ");

             gotoxy(x+40,y);
             printf ("net salary: ");


             gotoxy(x+17,y);
             printf("%s",node->Emp.aName);


             gotoxy(x+55,y);
             node->Emp.netSalary = node->Emp.salary - node->Emp.deduction + node->Emp.bonus;
             printf ("%f",node->Emp.netSalary);

             node = node->pNextEmp;
             y+=2;
         }

    }
}

void searchEmp (DataBase* db, char* str)
{
    Employee* temp = db->pFirstEmp;
    if (temp == NULL)
        printf("\n the list is empty");

    while ( (temp != NULL) && ( strcmpi(temp->Emp.aName, str) != 0)  )
        temp = temp->pNextEmp;

    if (temp == NULL)
    printf("\n Not found");
    else
    {
         printf("\n The searched employee is found: \n");

         x = 2;
         y = 6;
         gotoxy(x,y);
         printf("employee name: ");

         gotoxy(x+40,y);
         printf ("net salary: ");


         gotoxy(x+17,y);
         printf("%s",temp->Emp.aName);


         gotoxy(x+55,y);
         temp->Emp.netSalary = temp->Emp.salary - temp->Emp.deduction + temp->Emp.bonus;
         printf ("%f",temp->Emp.netSalary);

    }
}

void deleteEmp (DataBase* db, unsigned int id)
{
    Employee* temp = db->pFirstEmp;
    if (db->pFirstEmp == NULL)                               /* if there isnt any data in the list*/
        printf("\n there is no employees found already");

    while ( (temp != NULL) && (temp->Emp.id != id) )
        temp = temp->pNextEmp;

     if (temp == db->pFirstEmp && temp == db->pLastEmp)      /* if there is only one element in the list*/
    {
        db->pFirstEmp = db->pLastEmp = NULL;
        free(temp);
    }

    else if (temp == db->pFirstEmp)
    {
        db->pFirstEmp = temp->pNextEmp;
        temp->pNextEmp->pPrevEmp = NULL;
        free(temp);
    }

    else if (temp == db->pLastEmp)
    {
        db->pLastEmp = temp->pPrevEmp;
        temp->pPrevEmp->pNextEmp = NULL;
        free(temp);
    }

    else
    {
        temp->pNextEmp->pPrevEmp = temp->pPrevEmp;
        temp->pPrevEmp->pNextEmp = temp->pNextEmp;
        free(temp);
    }
}

void insertEmp (DataBase* db, Employee* e, int position)
{
    int iterator;
    Employee* temp;

    iterator = 1;

    if (position == 0 || position < 0)
    {
        numOfEmp--;
        printf(" \n\n  Invalid position");
        return;
    }

    if ( (position > 1) && (db->pFirstEmp == NULL) && (db->pLastEmp == NULL) )
    {
        printf(" \n\n list is empty .. cant insert at this position currently");
        numOfEmp--;
        return;
    }

      if (numOfEmp < position)
    {
         printf(" \n\n Cant insert at this position currently memory exceeded out bound");
         numOfEmp--;
         return;
    }


    if ( (position == 1) && (db->pFirstEmp == NULL) && (db->pLastEmp == NULL) )
    {

        e = pCreateNewEmp ();

        if (e == NULL)
        {
           printf("\n sorry there isn't enough space allocated");
           numOfEmp--;
           return;
        }
        appendEmployee (db, e);
        return;
    }

    if (position == 1)
    {

        e = pCreateNewEmp ();

        if (e == NULL)
        {
           printf("\n sorry there isn't enough space allocated");
           numOfEmp--;
           return;
        }

        db->pFirstEmp->pPrevEmp = e;
        e->pNextEmp = db->pFirstEmp;
        db->pFirstEmp = e;

        return;

    }


    temp = db->pFirstEmp;

    while ( (iterator < position ) && (temp != db->pLastEmp) )
    {
        temp = temp->pNextEmp;
        iterator++;
    }


    if (temp == db->pLastEmp)

    {

        if (e == NULL)
        {
           printf("\n sorry there isnt enough space allocated");
           numOfEmp--;
           return;
        }

        appendEmployee (db, e);
        return;
    }

    else
    {

        e = pCreateNewEmp ();

        if (e == NULL)
        {
           printf("\n sorry there isn't enough space allocated");
           numOfEmp--;
           return;
        }

        e->pNextEmp = temp; //1
        e->pPrevEmp = temp->pPrevEmp; //2
        temp->pPrevEmp->pNextEmp = e; //3
        temp->pPrevEmp = e; //4


    }

}


void swap (Employee* pTr1, Employee* pTr2)
{
    emp temp = pTr1->Emp;
    pTr1->Emp = pTr2->Emp;
    pTr2->Emp = temp;
}

void sortEmp( DataBase* db)
{
   int sorted;
   Employee* temp;
   while (1)
   {
       sorted = 1;
       temp = db->pFirstEmp;
        while ((temp != db -> pLastEmp))
        {

            if (strcmpi(temp->Emp.aName,temp->pNextEmp->Emp.aName )  > 0 )
            {
                swap( temp, temp->pNextEmp);
                sorted = 0;
            }
            temp = temp->pNextEmp;
        }

            if (sorted == 1)
            break;
    }
}


void freeList (DataBase* ll, Employee* node)
{
    Employee* temp;
    node = ll->pFirstEmp;
    while (node != NULL)
    {
        temp = ll->pFirstEmp;
        node = node->pNextEmp;
        ll->pFirstEmp = node;
        free(temp);
    }
}
/****************************** main *********************************/

void main (void)
{
    Employee* Node;
	int col = 5;
	int i, location;
	int pos = 0;
	int terminated = 0;
	unsigned int id;
	char menu [7][10] = {   "New      ", "Display  ", "Search   ","Delete   ","Insert   ","Sort     ",  "Exit     " };
	char ch;
    char empName[10];

    MyData.pFirstEmp = MyData.pLastEmp = NULL;


do
	{

	clrscr();

	printf("\n -------------------The Menu task--------------------");

	  for ( i = 0; i<7; i++)
	  {
		 gotoxy(10,col);

		 if ( pos == i)
		 {
		  textattr(HIGHLIGHTED_TEXT);
		  cprintf("%d%c %s", (i+1), ')', menu[i]);
		 }


		 else
		 printf("%s", menu[i]);

		 col += 2;
	  }

	textattr(NORMAL_TEXT);
	col = 5;
	ch = getch();

 switch (ch)
 {
	case UP_ARROW:

			flushall();

			if (pos == 0)
			pos = 6;

			else
			pos --;

		break;

	case DOWN_ARROW:

			flushall();

			if (pos == 6)
			pos = 0;
			else
			pos ++;
		break;

	case HOME:
			flushall();
			pos = 0;
		break;

	case END:
			flushall();
			pos = 6;
		 break;

	case ENTER:
			switch (pos)

				{
                    case NEW:
                        numOfEmp++;
                        clrscr();
                        newEmp(Node);
                     break;

                    case DISPLAY:
                        clrscr();
                        displayEmp();
                        getch();
                    break;

                    case SEARCH:
                        clrscr();
                        printf("\n please search name here: ");
                        gets(empName);
                        searchEmp(&MyData, empName);
                        getch();
                    break;

                    case DELETE:
                        clrscr();
                        printf("\n please insert id of the employee you want to delete: ");
                        scanf("%u", &id);
                        deleteEmp(&MyData, id);
                        numOfEmp--;
                        getch();
                    break;

                    case INSERT:
                        clrscr();
                        numOfEmp++;
                        printf("\n please insert location or order of the new employee: ");
                        scanf("%d", &location);
                        insertEmp(&MyData, Node, location);
                        getch();
                    break;

                    case SORT:
                        clrscr();
                        sortEmp(&MyData);
                        printf("\n list has been sorted");
                       getch();
                    break;

				case EXIT:
					freeList(&MyData, Node);
                    terminated = 1;
					break;

				}

		break;

	case ESCAPE:
			freeList(&MyData, Node);
			terminated = 1;
		break;

		default:
		clrscr();
		printf("\n\n bad ascii");
		break;
 }

	} while (!terminated);

}
