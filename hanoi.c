#include<stdio.h>
void towers(int,char,char,char);
int main()
{
	system("clear");
	int num;
	printf("Enter the number of discs:");
	scanf("%d",&num);
	printf("The sequence of moves involved in the tower of hanoi are:\n");
	towers(num,'A','C','B');
	return 0;
}
void towers(int num,char frompeg,char topeg,char auxpeg)
{
	if(num==1)
	{
		printf("Move disc 1 from peg %c to peg %c\n",frompeg,topeg);
		return;
	}
	towers(num-1,frompeg,auxpeg,topeg);
	printf("Move disk %d from peg %c to peg %c\n",num,frompeg,topeg);
	towers(num-1,auxpeg,topeg,frompeg);
}
