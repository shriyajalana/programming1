#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> stream={"A","B","A","C","A","B"};
    unordered_map<string,int> freq;
    string leader; int maxVotes=0;
    for(auto &vote:stream){
        freq[vote]++;
        if(freq[vote]>maxVotes){
            leader=vote; maxVotes=freq[vote];
        }
        cout<<"Leader: "<<leader<<" ("<<maxVotes<<")\n";
    }
}
