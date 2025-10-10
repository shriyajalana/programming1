#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> seats={1,2,3,4,5};
    vector<int> students={3,1,5,2};
    for(int s:students){
        auto it=seats.lower_bound(s);
        if(it==seats.end()) it=prev(seats.end());
        cout<<"Student "<<s<<" got seat "<<*it<<"\n";
        seats.erase(it);
    }
}
