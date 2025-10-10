#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={3,34,4,12,5,2};
    int sum=9;
    bitset<100> dp; dp[0]=1;
    for(int x:arr) dp|=(dp<<x);
    cout<<(dp[sum]?"YES":"NO")<<endl;
}
