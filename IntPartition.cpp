#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    vector<int> dp(n+1); dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) dp[j]+=dp[j-i];
    cout<<dp[n]<<endl; // 7
}
