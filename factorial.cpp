//Calculate factorial of a number
#include <iostream>
using namespace std;
int main()
{
    int i,fact=1,number;
    cout<<"Enter any Number: ";
    cin>>number;
    for(i=1;i<=number;i++)
    {
    fact *= i;
    }
    cout << "Factorial of " << nunmer << " = " << fact;    
    return 0;
}
