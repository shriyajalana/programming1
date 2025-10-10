#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> p={1,2,3,4};
    int n=p.size()-1;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1; dp[i][j]=1e9;
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1]);
        }
    }
    cout<<dp[0][n-1]<<endl; // 18
}
