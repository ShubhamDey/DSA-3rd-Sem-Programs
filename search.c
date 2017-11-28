#include<stdio.h>
#include<stdlib.h>
int arr[50];
void display(int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
}
void linear_search(int n)
{
	int k=1;
	int loc=-1;
	int item;
	printf("Enter the item to be searched:");
	scanf("%d",&item);
	while(loc==-1 && k<=n)
	{
		if(item==arr[k])
			loc=k;
		k=k+1;
	}
	if(loc==-1)
		printf("Search is unsuccessful");
	else
		printf("Search is successful at location %d",loc);
}
void binary_search(int n)
{
	int beg,end,mid,loc,item;
	beg=0;
	end=n-1;
	mid=(beg+end)/2;
	printf("Enter the item to be searched:");
	scanf("%d",&item);
	while(beg<=end && arr[mid]!=item)
	{
		if(item<arr[mid])
			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;
	}
	if(arr[mid]==item)
		loc=mid;
	else
		loc=-1;
	if(loc==-1)
		printf("Sreach is unsuccessful");
	else
		printf("Search is successful at location %d",loc);
}
void bubblesort(int n)
{

	int swap,temp,i,j;
	swap=1;
	i=1;
	while(swap==1 &&  i<n)
	{
		swap=0;
		j=0;
		while(j<n-i)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swap=1;
			}
			j=j+1;
		}
		i=i+1;
	}
}
void insertion_sort(int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0 && temp<arr[j];j--)
			arr[j+1]=arr[j];
			arr[j+1]=temp;
	}
}
void selection_sort(int n)
{
	int k,j,loc,temp;
	for(k=0;k<n-1;k++)
	{
		loc=k;
		for(j=k+1;j<n;j++)
		{
			if(arr[j]<arr[loc])
			loc=j;
		}
		if(loc!=k)
		{
			temp=arr[k];
			arr[k]=arr[loc];
			arr[loc]=temp;
		}
	}
}
main()
{
	system("clear");
	int i,n,m,ch;
	printf("Input the size of the array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nInput the data:");
		scanf("%d",&arr[i]);
	}
        do
	{
		printf("\nMENU\n1.Display\n2.Linear Search\n3.Binary Search\n4.Bubblesort\n5.Insertion Sort\n6.Selection Sort\nEnter your choice:");
		scanf("%d",&m);
		switch(m)
		{
			case 1:display(n);
				break;
			case 2:linear_search(n);
				break;
			case 3:insertion_sort(n);
				binary_search(n);
				break;
			case 4:bubblesort(n);
				break;
			case 5:insertion_sort(n);
				break;
			case 6:selection_sort(n);
				break;
			default:printf("Invalid option");
		}
		printf("\nDo you want to continue(0/1)?:");
		scanf("%d",&ch);
	}
	while(ch==1);
	return(0);
}
