#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



typedef struct stack
{
    int size, tos;
    int*stk;
}stack;

int initStack (stack* sk, int s)
{
    sk->size = s;
    sk->tos = 0;
    sk->stk = (int*)malloc (s*sizeof(int));
    if (sk->stk != NULL)
        return 1;
    else
        return  0;
}

int fullStack (stack s)
{
    if (s.tos == s.size)
        return 1;
    else
        return 0;
}


int emptyStack (stack s)
{
    if (s.tos == 0)
        return 1;
    else
        return 0;
}

int getPeek (stack s, int* data )
{
    if (emptyStack (s) == 0)
        return 0;
    else
    {
        *data = s.stk[s.tos-1];
        return 1;
    }
}

int push (stack* s, int data)
{
    if (fullStack(*s))
        return 0;
    s->stk[s->tos]= data;
    s->tos ++;
    return 1;
}

int pop (stack* s, int* data)
{
    if (emptyStack(*s))
        return 0;

    s->tos--;
    *data = s->stk[s->tos];
    return 1;
}

int main()
{
   stack myStack;
   int i;
   int p;

    clrscr();

    printf("\n________________implementation of static stack________________");

    initStack( &myStack, 10);
     printf("\n pushing process: \n\n");

    for (i = 0; i<myStack.size; i++)
    {
        push(&myStack, (i*2));
		printf("  %d", myStack.stk[myStack.tos-1]);
    }

    printf("\n\n popping process: \n\n");

    for (i = 0; i<myStack.size; i++)
    {
        pop(&myStack, &p);
		printf("  %d", p );
    }

    getch();
    return 0;
}
