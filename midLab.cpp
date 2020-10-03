#include<bits/stdc++.h>
using namespace std;
bool compare(int a[], int n, int m, int min) 
{ 
    int s = 1; 
    int sum = 0; 
   for (int i = 0; i < n; i++) 
    { 
        if (a[i] > min) 
            return false; 
     
        if (sum + a[i] > min) 
        { 
           
            s++; 
            sum = a[i]; 
  
            if (s>m) 
                return false; 
        } 
         else
            sum += a[i]; 
    } 
    return true; 
} 
int minpg(int a[], int n, int m) 
{ 
    int sm = 0; 
    if (n < m) 
        return -1;  
    for (int i = 0; i < n; i++) 
      {
      	sm += a[i];
		}      
    int h = 0, l = sm; 
    int result = INT_MAX; 
  
    while (h<=l) 
    {        
        int mid = (l+h) / 2; 
        if (compare(a, n, m, mid)) 
        { 
            result = min(result, mid); 
            l = mid - 1; 
        } 
        else           
            h = mid + 1; 
    } 
    return result; 
} 
int main()
{
	int n;
	cout<<"How many Number of books?  ";
	n=input();
	int a[n];
	printf("Eneter number of pages:\n");
	for(int i=0;i<n;i++)
	{
		a[i]=input();
	}
	int m;
	cout<<"Number of stuents"<<endl;
	m=input();
	cout<<"Min no of pages are:"<< minpg(a,n,m);
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
int input(){
int a;cin>>a;
if(cin.fail()){
cout<<"Incorrect Input, Enter Again -"<<endl;
cin.clear();
cin.ignore(20,'\n');
return input();
}
return a;
}
bool compare(int a[], int n, int m, int min) 
{ 
    int s = 1; 
    int sum = 0; 
   for (int i = 0; i < n; i++) 
    { 
        if (a[i] > min) 
            return false; 
     
        if (sum + a[i] > min) 
        { 
           
            s++; 
            sum = a[i]; 
  
            if (s>m) 
                return false; 
        } 
         else
            sum += a[i]; 
    } 
    return true; 
} 
int minpg(int a[], int n, int m) 
{ 
    int sm = 0; 
    if (n < m) 
        return -1;  
    for (int i = 0; i < n; i++) 
      {
      	sm += a[i];
		}      
    int h = 0, l = sm; 
    int result = INT_MAX; 
  
    while (h<=l) 
    {        
        int mid = (l+h) / 2; 
        if (compare(a, n, m, mid)) 
        { 
            result = min(result, mid); 
            l = mid - 1; 
        } 
        else           
            h = mid + 1; 
    } 
    return result; 
} 