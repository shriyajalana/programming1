#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=4,W=7;
    vector<int> wt={1,3,4,5}, val={1,4,5,7};
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            dp[i][w]=dp[i-1][w];
            if(w>=wt[i-1]) dp[i][w]=max(dp[i][w],dp[i-1][w-wt[i-1]]+val[i-1]);
        }
    }
    cout<<dp[n][W]<<endl; // 9
}
