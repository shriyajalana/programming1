#include <iostream>
using namespace std;
int add(int,int);
int main()
{
    int x,y,result; 
    cout<<"enter two integers: ";
    cin>>x>>y;
    result=add(x,y);
    cout<<"Sum of two numbers are:"<<result;
    return 0;
}
int add(int x, int y)
{
    if(y==0)
        return x;
    else
        return(1+add(x,y-1));
}
