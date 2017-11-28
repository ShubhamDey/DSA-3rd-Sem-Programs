#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct q
{
	int arr[MAX];
	int front,rear;
}queue;
int queue_full(queue*);
int queue_empty(queue*);
void display(queue*);
void enqueue(queue*);
void dequeue(queue*);
int main()
{
	system("clear");
	queue s,*ps;
	int item,ch;
	ps=&s;
	ps->front=0;
	ps->rear=0;
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue(ps);
				break;
			case 2:dequeue(ps);
				break;
			case 3:display(ps);
				break;
			case 4:exit(0);
			default:printf("\nWRONG CHOICE");
		}
	}
	return(0);
}	
int CQ_full(queue *ps)
{
	if((ps->rear==n && ps->front==1) || (front= rear+1))
		return 1;
	else
		return 0;
}
int queue_empty(queue *ps)
{
	if(ps->front==-1 && ps->rear==-1)
		return 1;
	else
		return 0;
}
void enqueue(queue *ps)
{
	int item;
	if(queue_full(ps))
	printf("Queue full");
	printf("\nEnter item:");
	scanf("%d",&item);
	if(ps->front==-1 && ps->rear==-1)
	{
		ps->front=0;
		ps->rear=0;
	}
	else
	ps->rear=ps->rear+1;
	ps->arr[ps->rear]=item;
}
void dequeue(queue *ps)
{
	int item;
	if(queue_empty(ps))
	printf("Queue empty");
	item=ps->arr[ps->front];
	if(ps->rear==ps->front)
	{
		ps->front=-1;
		ps->rear=-1;
	}
	else
	ps->front=ps->front+1;
	printf("\n%d dequeued",item);
}
void display(queue *ps)
{
	int i=ps->front;
	if(queue_empty(ps))
	{
		printf("\nQueue empty");
		return;
	}
	while(i<=ps->rear)
		{
			printf("%d\t",ps->arr[i]);
			i++;
		}
	return;
}
