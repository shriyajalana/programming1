#include <bits/stdc++.h>
using namespace std;

long long mergeCount(vector<int>& arr,int l,int r){
    if(r-l<=1) return 0;
    int m=(l+r)/2;
    long long inv=mergeCount(arr,l,m)+mergeCount(arr,m,r);
    vector<int> tmp; int i=l,j=m;
    while(i<m&&j<r){
        if(arr[i]<=arr[j]) tmp.push_back(arr[i++]);
        else {tmp.push_back(arr[j++]); inv+=m-i;}
    }
    while(i<m) tmp.push_back(arr[i++]);
    while(j<r) tmp.push_back(arr[j++]);
    copy(tmp.begin(),tmp.end(),arr.begin()+l);
    return inv;
}
int main(){
    vector<int> arr={2,4,1,3,5};
    cout<<mergeCount(arr,0,arr.size())<<endl; // 3
}
