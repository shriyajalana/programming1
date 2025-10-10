#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> chat={
        "hi how are you",
        "i am fine how about you",
        "i am good too"
    };
    unordered_map<string,int> freq;
    for(auto &line:chat){
        stringstream ss(line); string w;
        while(ss>>w) freq[w]++;
    }
    vector<pair<int,string>> arr;
    for(auto &[w,c]:freq) arr.push_back({c,w});
    sort(arr.rbegin(),arr.rend());
    for(auto &p:arr) cout<<p.second<<" -> "<<p.first<<"\n";
}
