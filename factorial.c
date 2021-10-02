//Using this code you can calculate the factorial of any given number

#include<stdio.h>
int main()
{
    printf("Enter the number to Find Factorial: ");
    scanf("%d",&n);
    int factorial=1;
    for(int i=1; n<=n; i++)
    {
        factorial=factorial*i;
    }
    printf("Factorial of a given number is: %d",n);
    return 0;
}
