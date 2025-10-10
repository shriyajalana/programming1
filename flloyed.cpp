#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=4;
    vector<vector<int>> dist={
        {0,5,1e9,10},
        {1e9,0,3,1e9},
        {1e9,1e9,0,1},
        {1e9,1e9,1e9,0}
    };
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k]<1e9 && dist[k][j]<1e9)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    for(auto &row:dist){for(auto x:row) cout<<x<<" "; cout<<"\n";}
}
