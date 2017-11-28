#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct stk
{
	int arr[MAX];
 	int top;
}stack;
int stack_empty(stack*);
int stack_full(stack*);
void push(stack*,int);
int pop(stack*);
int top(stack*);
void display(stack*);
int main()
{
	system("clear");
	stack s,*ps;
	int item,ch;
	ps=&s;
	ps->top=-1;
	while(1)
	{
		printf("\n\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter a number:");
				scanf("%d",&item);
				push(ps,item);
				break;
			case 2:item=pop(ps);
				if(item!=9999)
				printf("\n Popped item is %d",item);
				break;
			case 3:display(ps);
				break;
			case 4:exit(0);
			default:printf("\nWRONG CHOICE");
		}
	}
	return(0);
}
int stack_empty(stack *ps)
{
	if(ps->top==-1)
		return 1;
	else
		return 0;
}
int stack_full(stack*ps)
{
	if(ps->top==MAX-1)
		return 1;
	else
		return 0;
}
void push(stack *ps,int item)
{
	if(stack_full(ps))
	printf("\nOVERFLOW");
	else
	{
		ps->top=ps->top+1;
		ps->arr[ps->top]=item;
	}
	return;
}
int pop(stack *ps)
{
	int item;
	if(stack_empty(ps))
	{
		printf("\nUNDERFLOW");
		return(-9999);
	}
	item=ps->arr[ps->top];
	ps->top=ps->top-1;
	return item;
}
int top(stack *ps)
{
	if(stack_empty(ps))
	printf("\nUNDERFOW");
	else
	return ps->arr[ps->top];
}
void display(stack *ps)
{
	int i=0;
	if(stack_empty(ps))
	{
		printf("\nStack is empty");
		return;
	}
	else
	{
		while(i<=ps->top)
		{
			printf("%d\t",ps->arr[i]);
			i++;
		}
	}
	return;
}
