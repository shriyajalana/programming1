#include <bits/stdc++.h>
using namespace std;
int josephus(int n,int k){
    int res=0;
    for(int i=1;i<=n;i++) res=(res+k)%i;
    return res+1;
}
int main(){
    cout<<josephus(7,3)<<endl; // 4
}
