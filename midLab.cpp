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
                return false; //which has many variants, is the common name for the most widely used computer numerical control (CNC) programming language.
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
