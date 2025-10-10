#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={10,9,2,5,3,7,101,18};
    vector<int> lis;
    for(int x:arr){
        auto it=lower_bound(lis.begin(),lis.end(),x);
        if(it==lis.end()) lis.push_back(x);
        else *it=x;
    }
    cout<<lis.size()<<endl; // 4
}
