#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<pair<string,int>> q;
    q.push({"Alice", 5});
    q.push({"Bob", 2});
    q.push({"Charlie", 3});
    int time=0;
    while(!q.empty()){
        auto [name,items]=q.front(); q.pop();
        time+=items;
        cout<<name<<" finished at "<<time<<" mins\n";
    }
}
