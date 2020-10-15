//Using this code you can calculate the factorial of any given number
#include<stdio.h>
int main()
{
	int n,i,fact=1;
	scanf("%d",&fact);   //Enter a number
	for(i=1;i<=fact;i++)
	{
		fact=fact*i;   //storing each i in fact variable
	}
	printf("%d",fact);   //This will give you the output of the factorial of the given Number
	return 0;
}
//The End 
