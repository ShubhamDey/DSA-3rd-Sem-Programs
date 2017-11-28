#include<stdio.h>
#include<stdlib.h>
typedef struct stk
{
	int info;
	struct stk *next;
}stack;
void push(stack **top)
{
	stack *new_node;
	int item;
	printf("Input item:");
	scanf("%d",&item);
	new_node=(stack*)malloc(sizeof(stack));
	new_node->info=item;
	new_node->next=*top;
	*top=new_node;
}
int pop(stack **top)
{
	stack *temp;
	int item;
	if(*top==NULL)
	{
		printf("Stack underflow");
		return -999;
	}
	item=(*top)->info;
	printf("%d",item);
	temp=*top;
	*top=temp->next;
	free(temp);
	return(item);
}
void display(stack *top)
{
	stack *temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}
}
main()
{
	system("clear");
	stack *top=NULL;
	int n,ch;
	do{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:push(&top);
				break;
			case 2:pop(&top);
				break;
			case 3:display(top);
				break;
			case 4:exit(1);
			default:printf("Invalid option");
		}
		printf("\nDo you want to continue(0/1)?:");
		scanf("%d",&ch);
 	 }while(ch==1);
	 return(0);
}
