#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> lights={"Red","Green","Yellow"};
    int t=10;
    for(int i=0;i<t;i++){
        cout<<"Time "<<i<<": "<<lights[i%3]<<"\n";
    }
}
