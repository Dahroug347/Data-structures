
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
#define   EXIT                  2

/**** key Values ****/

/* extended keys*/
#define   UP_ARROW              72
#define   DOWN_ARROW            80
#define   HOME                  71
#define   END                   79
/* normal keys*/
#define   ENTER                 13
#define   ESCAPE                27

int key;
int x,y;

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

int numOfEmp = 0;
int flag;
emp *Emp;
int N;

emp newEmp (emp e)
{
	int row = 2, col =2;
	 if (numOfEmp > N)
	 {
		 gotoxy(row,col);
		 printf(" \n\nyou have reached max number of employees!");
	 }

	 else
	 {

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
		 gets(e.aName);

		 gotoxy(row+6,col+2);;
		 flushall();
		 scanf("%d",&e.age);

		 gotoxy(row+6,col+4);
		 flushall();
		 scanf("%u",&e.id);

		 gotoxy(row+32,col);
		 flushall();
		 scanf("%f",&e.salary);

		 gotoxy(row+32,col+2);
		 flushall();
		 scanf("%f",&e.deduction);

		 gotoxy(row+32,col+4);
		 flushall();
		 scanf("%f",&e.bonus);
	 }

	key = getch();
	return e;
}

void swap (emp* pTr1, emp* pTr2)
{
     emp temp = *pTr1;
    *pTr1 = *pTr2;
    *pTr2 = temp;
}

void selectionSort( emp* e, int size)
{
    int index, position, indexHolder = 0;

    for (position = 0; position <size; position++)
    {
        for (index = position+1; index<size; index++)
        {
            if (strcmpi(e[index].aName, e[indexHolder].aName)  < 0 )
                indexHolder = index;
        }
        swap( &e[position], &e[indexHolder]);
        indexHolder = position+1;
    }
}

void displayEmp (emp e)

{

	 gotoxy(x,y);
	 printf("employee name: ");

	 gotoxy(x+40,y);
	 printf ("net salary: ");


	 gotoxy(x+17,y);
	 printf("%s",e.aName);


	 gotoxy(x+55,y);
	 e.netSalary = e.salary - e.deduction + e.bonus;
	 printf ("%f",e.netSalary);


}

int getEmpName (emp* emp, int size, char* name)
{
    int i;

    for (i = 0; i<size; i++)
    {
       if (strcmpi(emp[i].aName, name) == 0)
        return i;
    }
    return -1;
}

void main (void)

{
	int col = 5;
	int i;
	int pos = 0;
	int terminated = 0;
	unsigned int id;
	char menu [3][10] = {   "New      ", "Display  ",  "Exit     " };
	char ch;
    char *empName;



do
	{

	clrscr();

	printf("\n -------------------The Menu task--------------------");

	  for ( i = 0; i<3; i++)
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
			pos = 2;

			else
			pos --;

		break;

	case DOWN_ARROW:

			flushall();

			if (pos == 2)
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
			pos = 2;
		 break;

	case ENTER:
			switch (pos)

				{
				case NEW:
					numOfEmp++;
					clrscr();
				 if (numOfEmp == 1)
					 {
						 printf("\n please enter the number of needed employees: ");
						 scanf("%d",&N);
						 Emp = (emp*)malloc(sizeof(emp)*N);
					 }
					Emp[numOfEmp-1] = newEmp(Emp[numOfEmp-1]);
				 break;

				case DISPLAY:
					clrscr();
					printf("\ninsert 'a'to display all or 'n' for name searching or any key for id searching: ");
					flushall();
					scanf("%c", &ch);

					if (ch == 'a')
						{
							x = 2;
							y = 10;

							gotoxy(x,y);
							for (i = 0; i<N; i++)
							{
							    selectionSort (Emp, N);
								displayEmp (Emp[i]);
								y+= 2;
							}
						 getch();
						}

                    else if (ch == 'n')
                    {
                        int val;
                        printf("\n\n please insert employee name to display his/her data: ");
						flushall();
                        scanf("%s",empName);
						val = getEmpName(Emp, N,empName);
							if (val == -1)
							printf("\n Not found! press any key to continue");

							else
                            displayEmp (Emp[val]);

							getch();

                    }

					else
					{
						printf("\n\n please insert employee ID to display his/her data: ");
						flushall();
						scanf("%u", &id);
						for (i = 0; i<numOfEmp; i++)
							{
								if (id == Emp[i].id)
								{
									flag = 1;
									displayEmp (Emp[i]);
								}
							}
							if (flag != 1)
                            {
                                clrscr();
                                printf("\n\n\n \t\t Invalid ID ! press any key to continue");
                            }


							getch();
					}

					break;

				case EXIT:
					free(Emp);
					terminated = 1;
					break;

				}

		break;

	case ESCAPE:
			free(Emp);
			terminated = 1;
		break;

		default:
		clrscr();
		printf("\n\n bad ascii");
		break;
 }

	} while (!terminated);

}
