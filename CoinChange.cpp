#include <bits/stdc++.h>
using namespace std;
int main(){
    int sum=5;
    vector<int> coins={1,2,5};
    vector<int> dp(sum+1); dp[0]=1;
    for(int c:coins){
        for(int i=c;i<=sum;i++) dp[i]+=dp[i-c];
    }
    cout<<dp[sum]<<endl; // 4
}
