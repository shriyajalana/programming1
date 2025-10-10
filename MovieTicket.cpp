#include <bits/stdc++.h>
using namespace std;

struct Cinema {
    vector<vector<int>> hall;
    Cinema(int r,int c){hall.assign(r,vector<int>(c,0));}
    bool book(int r,int c){
        if(hall[r][c]) return false;
        hall[r][c]=1; return true;
    }
};

int main(){
    Cinema c(3,3);
    cout<<c.book(1,1)<<endl; // 1
    cout<<c.book(1,1)<<endl; // 0
}
