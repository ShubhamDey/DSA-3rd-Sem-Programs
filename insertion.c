#include<stdio.h>
int n;
void display(int arr[])
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
}
void insert(int arr[],int k,int l)
{
	int i;
	for(i=n;i<=k;i++)
	{
		arr[i+1]=arr[i];
	}
	arr[k]=l;
	n+=1;
}
void delete(int arr[],int m)
{
	int i;
	for(i=m;i<=n;i++)
	{
		arr[m]=arr[m+1];
	}
	n-=1;
}
main()
{
	int arr[50],i,k,l,m;
	printf("Input the size of the array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nInput the data:");
		scanf("%d",&arr[i]);
	}
	printf("1.Display\n2.Insert\n3.Delete\n");
	printf("\nEnter your choice:");
	scanf("%d",&m);
	switch(m)
	{
		case 1:display(arr);
			break;
		case 2:printf("\nInput the position to be inserted:");
			scanf("%d",&k);		
			printf("\nInput the data:");
			scanf("%d",&l);
			insert(arr,k,l);
			printf("\nAfter insertion:");
			display(arr);
			break;
		case 3:printf("\nInput the position to be deleted:");
			scanf("%d",&m);
			delete(arr,m);
			printf("After deletion:");
			display(arr);
			break;
	}
}
