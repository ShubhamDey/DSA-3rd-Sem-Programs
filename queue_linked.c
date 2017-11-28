#include<stdio.h>
#include<stdlib.h>
typedef struct q
{
	int info;
	struct q *next;
}queue;
void enqueue(queue **front,queue **rear)
{
	queue *new_node;
	int item;
	printf("Input item:");
	scanf("%d",&item);
	new_node=(queue*)malloc(sizeof(queue));
	new_node->info=item;
	new_node->next=NULL;
	if(*front==NULL && *rear==NULL)
	{
		*front=new_node;
		*rear=new_node;
	}
	else
	(*rear)->next=new_node;
	*rear=new_node;
}
int dequeue(queue **front,queue **rear)
{
	queue *ptr=*front;
	if(*front=NULL)
	printf("Queue empty");
	else if(*front=*rear)
	{
		*front=NULL;
		*rear=NULL;
	}
	else
	*front=ptr->next;
	free(ptr);
	printf("%d dequeued",ptr);
}
void display(queue *front,queue *rear)
{
	queue *temp;
	temp=front;
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}
}
main()
{
	system("clear");
	queue *front=NULL;
	queue *rear=NULL;
	int n,ch;
	do{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:enqueue(&front,&rear);
				break;
			case 2:dequeue(&front,&rear);
				break;
			case 3:display(front,rear);
				break;
			case 4:exit(1);
			default:printf("Invalid option");
		}
		printf("\nDo you want to continue(0/1)?:");
		scanf("%d",&ch);
 	 }while(ch==1);
	 return(0);
}
