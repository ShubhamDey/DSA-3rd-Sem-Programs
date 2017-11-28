#include<stdio.h>
#include<stdlib.h>
struct node
	{
		int info;
		struct node *next;
	};
int num;
void create(struct node **head)
{
	struct node *new_node,*temp;
	int item,i=0;
	if(*head!=NULL)
	{
		printf("Linked list already created");
		return;
	}
	else
	{
		printf("No. of nodes:");
		scanf("%d",&num);
		while(i!=num)
		{
			printf("\nEnter item %d:",i+1);
			scanf("%d",&item);
			new_node=(struct node*)malloc(sizeof(struct node));
			new_node->info=item;
			new_node->next=NULL;
			if(*head==NULL)
			*head=new_node;
			else
			temp->next=new_node;
			temp=new_node;
			i++;
		}
		printf("\nLinked list created");
	}
}
void traverse(struct node **head)
{
	struct node *pos=*head;
	while(pos!=NULL)
	{
		printf("%d\t",pos->info);
		pos=pos->next;
	}
}
int count(struct node **head)
{
	struct node *temp=*head;
	int flag=0;
	while(temp!=NULL)
	{
		flag++;
		temp=temp->next;
	}
	return flag;
}
void search(struct node **head)
{
	struct node *temp;
	int item,pos=1;
	printf("\nEnter item:");
	scanf("%d",&item);
	temp=*head;
	while(temp!=NULL && temp->info!=item)
	{
		temp=temp->next;
		pos++;
	}
	if(temp==NULL)
	printf("\nItem not in list");
	else
	printf("\nitem found at node %d",pos);
}	
void insert_begin(struct node **head)
{
	struct node *new_node;
	int item;
	new_node=(struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("Link doesn't exist");
		return;
	}
	printf("Enter item:");
	scanf("%d",&item);
	new_node->info=item;
	new_node->next=*head;
	*head=new_node;
}
void insert_end(struct node **head)
{
	struct node *new_node,*temp;
	int item;
	new_node=(struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("Link dosen't exist");
		return;
	}
	printf("Enter item:");
	scanf("%d",&item);
	temp=*head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	new_node->info=item;
	temp->next=new_node;
	new_node->next=NULL;
}
void insert_any(struct node **head)
{
	struct node *new_node,*prev,*temp;
	int item,i=1,pos,flag;
	temp=*head;
	printf("New Position:");
	scanf("%d",&pos);
	flag=count(&(*head));
	if (pos==1)
	insert_begin(&(*head));
	else if (pos==flag+1)
	insert_end(&(*head));
	else
	{
		printf("\nNew item:");
		scanf("%d",&item);
		while(i<pos)
		{
			prev=temp;
			temp=temp->next;
			i++;
		}
		new_node=(struct node*)malloc(sizeof(struct node));
		prev->next=new_node;
		new_node->next=temp;
		new_node->info=item;
	}
}
void delete_begin(struct node **head)
{
	struct node *temp;
	temp=*head;
	if(temp==NULL)
	{
		printf("Link doesn't exist");
		return;
	}
	*head=temp->next;
	free(temp);
}
void delete_end(struct node **head)
{
	struct node *prev,*temp;
	temp=*head;
	if(temp==NULL)
	{
		printf("Link doesn't exist");
		return;
	}
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		free(temp);
		prev->next=NULL;
	}
	
}
void delete_any(struct node **head)
{
	struct node *prev,*temp;
	int item,i=1,pos,flag;
	temp=*head;
	printf("Enter position to be deleted:");
	scanf("%d",&pos);
	flag=count(&(*head));
	if(pos==1)
	delete_begin(&(*head));
	else if(pos==flag)
	delete_end(&(*head));
	else
	{
		while(i<pos)
		{
			prev=temp;
			temp=temp->next;
			i++;
		}
		prev->next=temp->next;
		free(temp);
	}
}
void reverse(struct node **head)
{
	struct node *temp,*prev,*ptr;
	temp=*head;
	prev=NULL;
	if(temp==NULL)
	{
		printf("List doesn't exist");
		return;
	}
	while(temp!=NULL)
	{
		ptr=temp->next;
		temp->next=prev;
		prev=temp;
		temp=ptr;
	}
	*head=prev;
}
void sort(struct node **head)
{
	struct node *temp,*ptr;
	int var;
	temp=*head;
	while(temp->next!=NULL)
	{
		temp=ptr->next;
		while(ptr!=NULL)
		{
			if(temp->info>ptr->info)
			{
				var=ptr->info;
				ptr->info=temp->info;
				temp->info=var;
			}
			ptr=ptr->next;
		}
		temp=temp->next;
	}
}
main()
{
	struct node *head=NULL;
	int c,d,flag;
	do
	{
		system("clear");
		printf("1.Create a linked list\n2.Traverse a linked list\n3.Count nodes\n4.Search nodes\n5.Insert node at begining\n6.Insert node at ending");
		printf("\n7.Insert node at any place\n8.Delete node from begining\n9.Delete node from ending\n10.Delete node from any place\n11.Reverse a linked list");
		printf("\n12.Sort a linked list\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:create(&head);
				break;
			case 2:traverse(&head);
				break;
			case 3:flag=count(&head);
				printf("\nList contains %d nodes",flag);
				break;
			case 4:search(&head);
				break;
			case 5:insert_begin(&head);
				break;
			case 6:insert_end(&head);
				break;
			case 7:insert_any(&head);
				break;
			case 8:delete_begin(&head);
				break;
			case 9:delete_end(&head);
				break;
			case 10:delete_any(&head);
				break;
			case 11:reverse(&head);
				break;
			case 12:sort(&head);
				break;
		}
		printf("\nDo you want to continue (0/1)?:");
		scanf("%d",&d);
	}
	while(d==1);
}
